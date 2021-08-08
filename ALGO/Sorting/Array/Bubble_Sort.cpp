#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

template <class RandomAccessIterator>
void bubble_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    for (auto i = first; i != last; ++i)
    {
        bool flag = false;
        for (auto j = first; j != last - 1 - (i - first); ++j)
        {
            if (*j > *(j + 1))
            {
                swap(*j, *(j + 1));
                flag = true;
            }
        }
        if (!flag)
            break;
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

    bubble_sort(arr, arr + size);

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}