#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void randomize(int arr[], int n)
{
    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand(time(0));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}