#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int size, int range)
{
    int temp[size], count[range + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < size; i++)
        ++count[arr[i]];

    for (int i = 1; i < range + 1; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < size; i++)
        temp[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;

    int range;
    cout << "Enter Range : ";
    cin >> range;

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

    counting_sort(arr, size, range); // Call from main()

    cout << "\nAfter Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}