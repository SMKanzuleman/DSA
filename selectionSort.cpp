#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr){
    int s = (int)arr.size();
    for(int i=0;i<s-1;i++){
        int smallIndex=i;
        for(int j=i+1;j<s;j++){
            if(arr[j]<arr[smallIndex]){
                smallIndex=j;
            }
        }
        swap(arr[i],arr[smallIndex]);
    }
}
int main() {
    vector<int>arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(2);
    for (int x : arr)
    {
       cout << x << ",";
    }
    cout<<endl;
    selectionSort(arr);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << "Bye Bye" << endl;
    return 0;
}