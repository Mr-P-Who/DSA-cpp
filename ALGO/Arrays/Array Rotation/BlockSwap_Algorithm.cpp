#include <bits/stdc++.h>
using namespace std;

// Swaps n elements starting at first_index with n elements starting at second_index
template <class T>
void swap(T *first_index, T *second_index, int n)
{
    for (int i = 0; i < n; ++i)
    {
        T temp = *(first_index + i);
        *(first_index + i) = *(second_index + i);
        *(second_index + i) = temp;
    }
}

template <class T>
void array_rotate(T arr[], int rotate_by, int size)
{
    /* Return If number of elements to be rotated 
    is zero or equal to array size */
    if (rotate_by == 0 || rotate_by == size)
        return;
    else if (rotate_by < size - rotate_by)
    {
        swap(arr + 0, arr + size - rotate_by, rotate_by);
        array_rotate(arr, rotate_by, size - rotate_by);
    }
    else if (rotate_by == size / 2)
    {
        swap(arr + 0, arr + size - rotate_by, rotate_by);
    }
    else
    {
        swap(arr + 0, arr + rotate_by, size - rotate_by);
        array_rotate(arr + size - rotate_by, rotate_by - (size - rotate_by), rotate_by);
    }
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    array_rotate(A, 3, *(&A + 1) - A);
    for (auto &&i : A)
    {
        cout << i << " ";
    }
    return 0;
}