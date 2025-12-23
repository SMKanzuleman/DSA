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
            if(arr[parent<arr[i]]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }

        }




    }
    
};

int main() {

    cout << "Hi KanzulEman" << endl;
    return 0;
}