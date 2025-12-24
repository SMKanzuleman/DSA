#include <iostream>
using namespace std;
int hoarePartition(int arr[], int L, int H)
{
    int pivot = arr[L];
    int i = L - 1;
    int j = H + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);


        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int L, int H)
{
    if (L < H)
    {
        int pi = hoarePartition(arr, L, H);
        quickSort(arr, L, pi); // subArray conatining values lesser than pivot
        quickSort(arr, pi + 1, H);   // subArray conatining  values greater than pivot
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
    int test[] = {20,10,40,30,50};
    int size= sizeof(test) / sizeof(test[0]);
    cout<<size<<endl;
    quickSort(test, 0, size - 1);
    printArray(test, size);
}