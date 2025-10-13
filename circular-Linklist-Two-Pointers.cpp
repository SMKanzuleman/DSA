#include <iostream>
using namespace std;
// Time complexity: O(1)
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
        node *newNode = new node(val);
        if (head == NULL){
            head=tail=newNode;
            tail->next=head;
            return;
        }
        else{
            newNode->next=tail->next;
            tail->next=newNode;
            head=newNode;
        }
    }
    void insertAtEnd(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void display()
    {
        if (head == NULL)
            return;
        node *temp = head;
        cout << "[ ";
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
                cout << ",";
        } while (temp != head);
        cout << " ]" << endl;
    }
};

int main() {
    cLL cll;
    // cll.insertAtStart(1);
    // cll.insertAtStart(2);
    // cll.insertAtStart(3);
    // cll.insertAtStart(4);
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.display();
    cout << "Bye Bye" << endl;
    return 0;
}
