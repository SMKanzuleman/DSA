#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

// Randomized Lomuto partition
int part(int a[], int l, int r)
{
    int rnd = l + rand() % (r - l + 1);
    cout << "Random pivot chosen: " << rnd << endl;
    swap(a[rnd], a[r]); // move pivot to end

    int i = l - 1;
    int p = a[r]; // pivot

    for (int j = l; j < r; j++)
    {
        if (a[j] < p)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

// QuickSort
void qs(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = part(a, l, r);
        qs(a, l, pi - 1);
        qs(a, pi + 1, r);
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
    int a[] = {6, 8, 23, 21, 62, 72, 20, 2};
    int n = sizeof(a) / sizeof(a[0]);
    qs(a, 0, n - 1);
    pr(a, n);
}
