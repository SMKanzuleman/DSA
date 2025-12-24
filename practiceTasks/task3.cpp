#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1; // size of left subarray
    int n2 = r - m;     // size of right subarray

    int L[30], R[30]; // temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i]; // copy left
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j]; // copy right

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    { 
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++]; // copy remaining left
    while (j < n2)
        a[k++] = R[j++]; // copy remaining right

    pr(a, r + 1); 
}
void ms(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; 
        ms(a, l, m);             
        ms(a, m + 1, r);         
        merge(a, l, m, r);       
    }
}
void pr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {5,2,9,1,5,6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    pr(a, n); // print original array
    cout << endl;
    ms(a, 0, n - 1); 
    cout << "\nSorted array: ";
    pr(a, n); // print final sorted array
}
