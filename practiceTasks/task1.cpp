#include <iostream>
using namespace std;
int factorial(int n)
{
    int result=1;
    for (int i = n; i > 1; i--)
    {
        result*=i;
    }
    return result;
}
int main()
{
    
    cout << "Factorial "<<factorial(5) << endl;
    return 0;
}