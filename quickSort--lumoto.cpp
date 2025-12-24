#include <iostream>
using namespace std;
int lumotoPartition(int arr[], int L, int H)
{
    int i = L ;
    int pivot = arr[H]; // pivot
    for (int j = L; j < H; j++)
    {
        if (arr[j] < pivot) // comparing pivot with array indepivotes
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[H]);
    return i;
}
void quickSort(int arr[], int L, int H)
{
    if (L < H)
    {
        int pi = lumotoPartition(arr, L, H);
        quickSort(arr, L, pi - 1);// subArray conatining values lesser than pivot
        quickSort(arr, pi + 1, H);  // subArray conatining  values greater than pivot
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
    int test[] = {6, 8, 23, 21, 62, 72, 20, 2};
    int size= sizeof(test) / sizeof(test[0]);
    quickSort(test, 0, size - 1);
    printArray(test, size);
}