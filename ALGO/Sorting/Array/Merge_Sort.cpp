#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++, i++;
        }
        else
        {
            temp[k] = arr[j];
            k++, j++;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        k++, i++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        k++, j++;
    }

    for (int x = 0; x < r - l + 1; x++)
    {
        arr[l + x] = temp[x];
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

template <class RandomAccessIterator>
void merge(RandomAccessIterator left, RandomAccessIterator middle, RandomAccessIterator right)
{
    auto temp[right - left] = {*left};
    int k = 0;
    auto i = left, j = middle;
    while (i != middle && j != right)
    {
        if (*i <= *j)
        {
            temp[k] = *i;
            ++i;
        }
        else
        {
            temp[k] = *j;
            ++j;
        }
        ++k;
    }
    while (i != middle)
    {
        temp[k] = *i;
        ++i, ++k;
    }
    while (j != right)
    {
        temp[k] = *j;
        ++j, ++k;
    }
    for (auto &x : temp)
    {
        *left = *x;
        left++;
    }
}

template <class RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first < last)
    {
        auto mid = first + distance(first, last) / 2;
        merge_sort(first, mid);
        merge_sort(mid, last);
        merge(first, mid, last);
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

    merge_sort(arr, 0, size - 1); // Call from main()

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}