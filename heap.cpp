#include <iostream>
using namespace std;
static const int MAX = 100;
class Heap // Max heap
{
    int arr[MAX];
    int size;

public:
    Heap()
    {
        size = 0;
    }
    void insert(int key)
    {
        int i = ++size;
        arr[i] = key;
        while (i > 1) // Bottom to Top
        {
            int parent = i / 2;
            if (arr[i] > arr[parent])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void delNode()
    {
        arr[1] = arr[size];
        size--;
        int i = 1;
        heapify(arr, size, i);
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << i << "  ";
        }
        cout << endl
             << "-------------------------------" << endl;
    }
    void print(int dummy[], int n)
    {

        for (int i = 1; i <= n; i++)
        {
            cout << dummy[i] << "  ";
        }
        cout << endl
             << "-------------------------------" << endl;
    }
    void heapify(int arr[], int n, int i) // Shiftdown
    {
        while (true)
        {
            int largest = i;
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (leftChild <= n && arr[leftChild] > arr[largest])
            {
                largest = leftChild;
            }
            if (rightChild <= n && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
    void makeheap(int a[], int n)
    {
        for (int i = n / 2; i >= 1; i--)
            heapify(a, n, i);
    
    }
    void heapSort(int a[], int n)
    { // O(n)+O(n-1)*logn=O(nlogn)

        makeheap(a,n); 
        int t=n;
        while(t>1){
            //first step
            swap(a[1],a[t]);
            t--;
            //second step
            heapify(a,t,1);
        }
    }
};

int main()
{
    Heap h;
    // Insertion
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(15);
    h.insert(28);
    h.insert(75);
    h.print();
    // Deletion
    h.delNode();
    h.print();
    // Heapify 
    Heap h2;
    int test[6] = {-1, 54, 53, 55, 52, 50};
    h2.makeheap(test, 5);
    h2.print(test,5);
    // Heap Sort
    h2.heapSort(test, 5);
    h2.print(test, 5);

    cout << "Hi KanzulEman" << endl;
    return 0;
}
