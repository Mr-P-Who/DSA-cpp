#include <bits/stdc++.h>
using namespace std;

double find_mean(int arr[], int size)
{
    if (!size)
        return 0.0;
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return double(sum) / double(size);
}

int main()
{
    int a[] = {1, 3, 4, 2, 7, 5, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Mean = " << find_mean(a, n) << endl;
    return 0;
}