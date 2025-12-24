#include <iostream>
using namespace std;
//Big O(nlogn)
void mergSort(int arr[], int L, int R) 
{
    if (L < R) // log(n)
    {
        int mid = L + (R - L) / 2;
        mergSort(arr, L, mid);
        mergSort(arr, mid + 1, R);
        merg(arr, L, mid, R); //(n)
    }
}
void merg(int arr[], int L, int mid, int R)
{
    int size=(R-L)+1;
    int temp[size];
    int i = L;
    int j = mid + 1;
    int k=0;//for iterating temp array
    while (i <= mid && j <= R)
    {
        if (arr[i] < arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    //copy remaining list elements to temp array data 
    while (i <= mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while (j <= R)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    //copying temp array data to orignal array
    for (int i = L; i <= R; i++)
    {
        arr[i] = temp[i-L];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int test[8] = {6, 8, 23, 21, 62, 72, 20, 2};
    mergSort(test, 0, 7);
    printArray(test,8);
}