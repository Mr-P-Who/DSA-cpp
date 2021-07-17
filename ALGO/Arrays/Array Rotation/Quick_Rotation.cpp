#include <bits/stdc++.h>
using namespace std;

void array_rotate(int arr[], int rotate_by, int size)
{
    for (int i = rotate_by; i < rotate_by + size; ++i)
    {
        cout << arr[i % size] << " ";
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;
    array_rotate(arr, k, n);
    cout << endl;

    k = 3;
    array_rotate(arr, k, n);
    cout << endl;

    k = 4;
    array_rotate(arr, k, n);
    cout << endl;

    return 0;
}