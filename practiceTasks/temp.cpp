#include <iostream>
using namespace std;

// Hoare partition
int hoarePart(int a[], int l, int r)
{
    int pivot = a[l]; // choose first element as pivot
    int i = l - 1, j = r + 1;

    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot); 
        do
        {
            j--;
        } while (a[j] > pivot); 

        if (i >= j)
            return j;     
        swap(a[i], a[j]); // swap elements on wrong sides
    }
}

// Quick Sort using Hoare partition
void qs(int a[], int l, int r)
{
    if (l < r)
    {
        int p = hoarePart(a, l, r);
        qs(a, l, p);     // left subarray
        qs(a, p + 1, r); // right subarray
    }
}

// Print array
void pr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {8, 7, 3, 2, 1, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    pr(a, n);

    qs(a, 0, n - 1);

    cout << "\nSorted array: ";
    pr(a, n);
}
