#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

template <class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    for (auto i = first + 1; i != last; i++)
    {
        auto key = *i;
        auto j = i - 1;
        for (; j != first - 1 && *j > key; --j)
        {
            *(j + 1) = *j;
        }
        *(j + 1) = key;
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

    insertion_sort(arr, size);

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}