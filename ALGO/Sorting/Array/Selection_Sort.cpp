#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

template <class RandomAccessIterator>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    for (auto i = first; i != last - 1; ++i)
    {
        auto min = i;
        for (auto j = i + 1; j != last; ++j)
        {
            if (*j < *min)
                min = j;
        }
        if (min != i)
            swap(*i, *min);
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

    selection_sort(arr, arr + size);

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}