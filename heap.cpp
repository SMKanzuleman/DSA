#include <iostream>
using namespace std;
class Heap{
    int arr[100];
    int size;
    public:
    Heap(){
        size=0;
    }
    void insert(int key){
        int i=size;
        arr[size++]=key;
        while(i>0){
            int parent=(i-1)/2;
            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
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

    cout << "Hi KanzulEman" << endl;
    return 0;
}