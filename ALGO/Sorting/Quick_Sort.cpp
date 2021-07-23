#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) // Hoare
{
    int low = s - 1, high = e + 1, pivot = arr[(s + e) / 2];
    while (true)
    {
        do
        {
            ++low;
        } while (arr[low] < pivot);
        do
        {
            --high;
        } while (arr[high] > pivot);
        if (low >= high)
            return high;
        else
            swap(arr[low], arr[high]);
    }
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
    auto pivot = *beg, low = beg - 1, high = end + 1;
    while (true)
    {
        do
        {
            ++low;
        } while (*low < pivot);
        do
        {
            --high;
        } while (*high > pivot);
        if (low >= high)
            return high;
        else
            swap(*low, *high);
    }
}

template <class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first < last)
    {
        auto partition_point = partition(first, last);
        quick_sort(first, partition_point); // Using Hoare
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