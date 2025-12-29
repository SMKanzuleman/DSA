#include <iostream>
using namespace std;    
void printArray(int arr[], int size,int i)
{
    if(i==size) 
        return;
    cout<<arr[i]<<" ";
    printArray(arr,size,i+1);
}
int main() {

    int krr[]={1,2,3,4,5};
    printArray(krr,5,0);
    return 0;
}