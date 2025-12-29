#include <iostream>
using namespace std;
int BP(int number,int times){
    if(times==0)
        return 1;
    return number*BP(number,times-1);
};

int main() {

    int number,times;
    cout << "Enter number and power : " << endl;
    cin>>number>>times;
    cout<< "Result is "<<BP(number,times) << endl;
    return 0;
}