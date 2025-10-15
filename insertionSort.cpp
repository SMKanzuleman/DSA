#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& arr)
{
    int s = (int)arr.size();
    for (int i = 1; i < s; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(2);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    insertionSort(arr);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << "Bye Bye" << endl;
    return 0;
}