#include <iostream>
#include <vector>
using namespace std;
void merg(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + start] = temp[i];
    }
}
void mergSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergSort(arr, start, mid);
        mergSort(arr, mid + 1, end);
        merg(arr, start, mid, end);
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
    mergSort(test, 0, test.size() - 1);
    printVector(test);
}