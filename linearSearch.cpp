#include <iostream>
using namespace std;

// Function that searches and returns index
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i; // return immediately when found
    }
    return -1; // not found
}

int main()
{
    int arr[6] = {2, 3, 4, 5, 6, 7};
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, 6, target);

    if (result != -1)
        cout << target << " is found at index " << result << " :)\n";
    else
        cout << "Target not found :(\n";

    return 0;
}

