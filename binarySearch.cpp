#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    bool found=false;
    int L=0,H=n-1;
    for(;L<=H;){
        int M=L+(H-L)/2;
        if(arr[M]==target){
            // cout << target << " is found at " << M << " index:)";
            found=true;
            return M;
        }
        else if(arr[M]<target){

            L=M+1;
        }
        else{

            H=M-1;
        }
    }
    if(!found){

        return -1;
    }
}
int main()
{
    int arr[7] = {2, 3, 4, 5, 6,7, 8};
    int a=binarySearch(arr,7,6);
    if(a!=-1){
        cout<<"Found at "<<a<<" index";
    }
    else
    cout<<"Not Found"; 
}