#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = e, low = s, high = e - 1;
    while (true)
    {
        while (arr[low] < arr[pivot])
            ++low;
        while (high != s && arr[high] > arr[pivot])
            --high;
        if (low >= high)
            break;
        else
            swap(arr[low], arr[high]);
    }
    swap(arr[low], arr[pivot]);
    return low;
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

template <class RandomAccessIterator>
auto partition(RandomAccessIterator beg, RandomAccessIterator end)
{
    auto pivot = end - 1, low = beg, high = pivot - 1;
    while (true)
    {
        while (*low < *pivot)
            ++low;
        while (high != beg && *high > *pivot)
            --high;
        if (low >= high)
        {
            break;
        }
        else
        {
            swap(*low, *high);
        }
    }
    swap(*low, *pivot);
    return low;
}

template <class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first < last)
    {
        auto partition_point = partition(first, last);
        quick_sort(first, partition_point - 1);
        quick_sort(partition_point + 1, last);
    }
}

int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;

    int arr[size];
    cout << "Enter Elements : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nBefore Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    quick_sort(arr, 0, size - 1); // Call from main()

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}