#include <iostream>
using namespace std;
int addNnumbers(int n){
    if(n==0)
        return 0;
    return n+addNnumbers(n-1);
}

int main() {

    cout << "Hi KanzulEman" << endl;
    cout<< "Sum is "<<addNnumbers(5) << endl;
    return 0;
}