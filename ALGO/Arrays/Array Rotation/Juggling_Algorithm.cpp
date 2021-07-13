#include <bits/stdc++.h>
using namespace std;

template <class T>
inline T gcd(const T &a, const T &b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Juggling Algorithm
template <class T>
void array_rotate(T arr[], int rotate_by, int size)
{
    rotate_by %= size; // Handles if rotate_by > size
    int num_cycles = gcd(size, rotate_by);
    int j, d;
    T temp;
    for (int i = 0; i < num_cycles; ++i)
    {
        temp = arr[i];
        j = i;
        while (true)
        {
            d = (j + rotate_by) % size;
            if (d == i)
                break;
            else
            {
                arr[j] = arr[d];
                j = d;
            }
        }
        arr[j] = temp;
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
