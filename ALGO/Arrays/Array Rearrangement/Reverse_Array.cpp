#include <bits/stdc++.h>
using namespace std;

template <class T>
void reverse_array(T *start, T *end)
{
    while (start < end)
    {
        swap(*start, *end);
        ++start;
        --end;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, arr + n - 1);
    cout << "Reversed Array : " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}