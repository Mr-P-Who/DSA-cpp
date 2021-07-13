#include <bits/stdc++.h>
using namespace std;

template <class T>
void reverse_array(T arr[], int start, int end)
{
    while (start < end)
    {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        ++start, --end;
    }
}

template <class T> // Reversal Algorithm
void array_rotate(T arr[], int rotate_by, int size)
{
    rotate_by %= size;
    reverse_array(arr, 0, rotate_by - 1);
    reverse_array(arr, rotate_by, size - 1);
    reverse_array(arr, 0, size - 1);
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