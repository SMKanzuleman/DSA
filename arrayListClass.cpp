#include <iostream>
using namespace std;
class arrayList
{
    static const int maxSize = 1000;
    int arr[maxSize];
    int uSize;
public:
    arrayList() { uSize = 0; }
    void InsertAtEnd(int x)
    {
        if (!isFull())
        {
            arr[uSize++] = x;
        }
    }
    void InsertAtAnyIndex(int x, int i)
    {
        if (!isFull())
        {
            shiftRight(i, uSize);
            arr[i] = x;
            uSize++;
        }
    }
    int getSize()
    {
        return uSize;
    }
    void display()
    {
        for (int i = 0; i < uSize; i++)
        {
            cout << arr[i] << ",";
        }
        cout<<endl;
    }
    void shiftRight(int start, int end)
    {
        for (int j = end; j > start; j--)
            arr[j] = arr[j - 1];
    }
    void shiftLeft(int start, int end)
    {
        for (int j = start; j < end; j++)
            arr[j] = arr[j + 1];
    }
    bool isFull()
    {
        if (maxSize == uSize)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (uSize==0)
            return true;
        else
            return false;
    }
    bool search(int a)
    {
        for (int i = 0; i < uSize; i++)
        {
            if (arr[i] == a)
                return true;
        }
        return false;
    }
    void setIndex(int value,int index){
        arr[index] = value;
    }
    void deleteAtEnd(){
        uSize--;
    }
    void deleteAtAnyIndex(int i){
        shiftLeft(i,uSize);
        uSize--;
    }
    void clear(){
        uSize=0;
    }

};
 
int main()
{
    arrayList a1;
    a1.InsertAtEnd(3);
    a1.InsertAtEnd(5);
    a1.InsertAtEnd(8);
    a1.InsertAtEnd(2);
    a1.InsertAtEnd(9);
    a1.InsertAtEnd(0);
    a1.display();
    a1.setIndex(69,3);
    a1.display();
    a1.deleteAtAnyIndex(3);
    a1.display();
    if(a1.search(0)){
        cout<<"Found!";
    }
    a1.clear();
    a1.InsertAtEnd(99);
    cout<<endl;a1.display();
    return 0;
}