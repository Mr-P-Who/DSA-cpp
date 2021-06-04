#include <iostream>
#include <cmath>
using namespace std;

bool isprime(const long long &n)
{
    // Special Cases
    if (n <= 1) // 0 & 1 are not prime
        return false;
    else if (n == 2) // 2 is prime
        return true;
    else if (n & 1) // only odd numbers are checked
    {
        for (long long i = 3; i <= floor(sqrt(n)) + 1; i += 2)
        {
            if (!(n % i))
                return false;
        }
        return true;
    }
    else // even numbers are not prime
        return false;
}

int main()
{
    cout << "Enter A Number : ";
    long long num;
    cin >> num;

    cout << "Is " << num << " Prime : " << boolalpha << isprime(num);
}