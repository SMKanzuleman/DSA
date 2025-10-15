#include <iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& a)
{
    int s=(int)a.size();
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i-1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    } 
}
int main()
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(76);
    arr.push_back(42);
    arr.push_back(2);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    bubbleSort(arr);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << "\nBye Bye" << endl;
    return 0;
   
}
