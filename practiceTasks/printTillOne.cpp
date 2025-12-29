#include <iostream>
using namespace std;
void printTillOne(int n)
{
    if (n == 0)//base case
        return;
    cout << n << ",";
    return printTillOne(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printTillOne(n);
    cout << "Hi KanzulEman" << endl;
    return 0;
}