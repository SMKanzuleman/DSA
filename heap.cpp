#include <iostream>
using namespace std;

class Heap{
    int arr[100];
    int size=-1;
    public:
    Heap(){
        size=0;
    }
    void insert(int key){
        arr[size++]=key;
    }
};

int main() {

    cout << "Hi KanzulEman" << endl;
    return 0;
}