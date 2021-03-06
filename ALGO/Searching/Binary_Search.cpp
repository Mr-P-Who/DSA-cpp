#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int size, int val)
{
    int l = 0, r = size - 1;
    do
    {
        int m = (l + r) / 2;
        if (arr[m] < val)
            l = m + 1;
        else if (arr[m] > val)
            r = m - 1;
        else
            return m;
    } while (l <= r);
    return -1;
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

    int element;
    cout << "Enter Element To Be Searched : ";
    cin >> element;

    sort(arr, arr + size);

    int index = binary_search(arr, size, element);
    index == -1 ? cout << "Search Not Found !" : cout << "Element Found At Index = " << index;

    return 0;
}