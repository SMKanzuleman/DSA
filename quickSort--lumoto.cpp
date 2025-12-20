#include <iostream>
#include <vector>
using namespace std;
int lumotoPartition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int x = arr[end]; // pivot
    for (int j = start; j < end; j++)
    {
        if (arr[j] < x) // comparing pivot with array indexes
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}
void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pi = lumotoPartition(arr, start, end);
        quickSort(arr, start, pi - 1);// subArray conatining values lesser than pivot
        quickSort(arr, pi + 1, end);  // subArray conatining  values greater than pivot
    }
}
void printVector(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}
int main()
{
    vector<int> test = {6, 8, 23, 21, 62, 72, 20, 2};
    quickSort(test, 0, test.size() - 1);
    printVector(test);
}