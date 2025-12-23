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
        while (i > 1)
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
        while (i <= size)
        {
            int leftChld = 2 * i;
            int rightChld = 2 * i + 1;
            int largest = i;
            if (leftChld <= size && arr[leftChld] > arr[largest])
            {
                largest = leftChld;
            }
            if (rightChld <= size && arr[rightChld] > arr[largest])
            {
                largest = rightChld;
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
    void heapify(int arr[], int n, int i)
    {
        while (i >= 1)
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
        size = n;
        for (int i = 1; i <= n; i++)
            arr[i] = a[i];

        for (int i = n / 2; i >= 1; i--)
            heapify(arr, size, i);
    }
};

int main()
{
    Heap h;
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(15);
    h.insert(28);
    h.insert(75);
    h.print();
    h.delNode();
    h.print();
    Heap h2;
    int test[6] = {-1,54, 53, 55, 52, 50};
    h2.makeheap(test,5);
    h2.print();
    cout << "Hi KanzulEman" << endl;
    return 0;
}
