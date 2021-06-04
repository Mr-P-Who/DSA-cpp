// List All Prime Numbers Before 'N'
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<bool> sieve_of_eratosthenes(const long long &n)
{
    // vector<bool> : template specialisation of vector that requires space and is more efficient
    vector<bool> prime(n, true); // Assuming every number as prime

    // Special Cases
    prime[0] = prime[1] = false; // 0 & 1 are not prime
    prime[2] = true;             // 2 is prime

    //Mark all even numbers as not prime
    for (long long i = 4; i < n; i += 2)
        prime[i] = false;

    // Sieve
    for (long long i = 3; i <= sqrt(n); i += 2) // Only need to visit odd numbers
    {
        // If current number is true (a.k.a untouched) means it is prime
        if (prime[i])
        {
            // if square of current number exceeds 'n'(max size of vector)
            //Then no further checking is required in the sieve as the next numbers will also exceed 'n'(max size of vector)
            if (i * i >= n)
                break; // Hence breaking the loop

            // Mark multiples of 'i' as not prime
            for (long long j = i * i; j < n; j += i) // Mark multiples starting from i^2
                prime[j] = false;
        }
    }
    return prime;
}

int main()
{
    cout << "Enter A Number : ";
    long long n;
    cin >> n;

    cout << "All Prime Numbers Before " << n << " : \n";

    auto v = sieve_of_eratosthenes(n);
    for (long long i = 0; i < n; ++i)
    {
        if (v[i])
            cout << i << "\n";
    }
    system("pause");
    return 0;
}