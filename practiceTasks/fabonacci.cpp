
#include <iostream>
using namespace std;
int fabonacci(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    return fabonacci(n-1)+fabonacci(n-2);
}

int main() {

    int n;
    cout<<"Enter a number for fabonacci: ";
    cin>>n;
    cout << "Fabonacci of "<<n<<" is "<<fabonacci(n) << endl;

    return 0;
}