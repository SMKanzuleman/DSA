#include <iostream>
#include <vector>
using namespace std;
int horsPartition(vector<int> &arr, int start, int end)
{
    int x = arr[start];
    int i = start - 1;
    int j = end + 1;
    while (true)
    {
        do
        {
            j = j - 1;
        } while (arr[j] > x);
        do
        {
            i = i + 1;
        } while (arr[i] < x);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        return j;
    }
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pi = horsPartition(arr, start, end);
        quickSort(arr, start, pi - 1); // subArray conatining values lesser than pivot
        quickSort(arr, pi + 1, end);   // subArray conatining  values greater than pivot
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
    vector<int> test = {20,10,40,30,50};
    quickSort(test, 0, test.size() - 1);
    printVector(test);
}