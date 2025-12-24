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
int lumotoPartition(int arr[], int L, int H)
{
    int pivot = arr[H];
    int i = L - 1;
    for (int j = L; j < H; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[H]);
    return i;
}
int lumotoRandom(int arr[], int L, int H)
{
    int randomIndex = L + rand() % (H - L + 1);
    cout<<"Random pivot choosed :"<<randomIndex<<endl;
    // swap random pivot with last element
    swap(arr[randomIndex], arr[H]);
    return lumotoPartition(arr, L, H);

}
int HoarsRandom(int arr[], int L, int H)
{
    int randomIndex = L + rand() % (H - L + 1);
    cout << "Random pivot choosed :" << randomIndex << endl;
    // swap random pivot with last element
    swap(arr[randomIndex], arr[H]);
    return hoarePartition(arr, L, H);
}

void quickSort(int arr[], int L, int H)
{
    if (L < H)
    {
        int pi = HoarsRandom(arr, L, H);
        quickSort(arr, L, pi - 1);// subArray conatining values lesser than pivot
        quickSort(arr, pi + 1, H);  // subArray conatining  values greater than pivot
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int test[] = {20, 10, 40, 30, 50};
    int size = sizeof(test) / sizeof(test[0]);
    cout << size << endl;
    quickSort(test, 0, size - 1);
    printArray(test, size);
}