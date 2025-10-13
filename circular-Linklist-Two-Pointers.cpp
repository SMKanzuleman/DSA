#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int value) {
        this->data = value;
        this->next = NULL;
    }
    node() {
        this->next = NULL;
    }
};
class cLL {
    node *head;
    node *tail;
    public:
    cLL() {
        head = NULL;
        tail = NULL;
    }
    void insertAtStart(int val){
        
    }

};

int main() {
    cout << "Bye Bye" << endl;
    return 0;
}