#include <iostream>
using namespace std;
class Heap
{
    int arr[100];
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
            if (arr[parent] < arr[i])
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
        int i = 1;
        size--;
        while (i <= size)
        {
            int leftChld = 2 * i;
            int rightChld = 2 * i + 1;
            int largest=i;
            if (leftChld <= size && arr[leftChld] > arr[rightChld])
            {
                largest = leftChld;
            }
            if (rightChld <= size && arr[rightChld] > arr[leftChld])
            {
                largest = rightChld;
            }
            if (largest!=i)
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

    cout << "Hi KanzulEman" << endl;
    return 0;
}