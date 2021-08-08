#include <bits/stdc++.h>
using namespace std;

double find_median(int arr[], int size)
{
    if (!size)
        return 0.0;
    nth_element(arr, arr + size / 2, arr + size);
    if (size & 1)
        return double(arr[size / 2]);
    else
        return 0.5 * (arr[size / 2] + *max_element(arr, arr + size / 2));
}

int main()
{
    int a[] = {1, 3, 4, 2, 7, 5, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Median = " << find_median(a, n) << endl;
    return 0;
}