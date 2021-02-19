#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
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

    int index = linear_search(arr, size, element);
    index == -1 ? cout << "Search Not Found !" : cout << "Element Found At Index = " << index;

    return 0;
}