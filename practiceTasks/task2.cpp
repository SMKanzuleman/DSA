#include <iostream>
using namespace std;

// Global counter for fib(2) calls
int countFib2 = 0;

int fib(int n)
{
    if (n == 2)
    {
        countFib2++; // increment counter when fib(2) is called
    }
    if (n <= 1)
        return n; // base case
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 5;
    int result = fib(n);

    cout << "fib(" << n << ") = " << result << endl;
    cout << "fib(2) was called " << countFib2 << " times" << endl;

    return 0;
}
