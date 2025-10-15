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
    // Time Complexity: O(1)
    cLL() {
        head = NULL;
        tail = NULL;
    }
    // Time Complexity: O(1)
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
    // Time Complexity: O(1)
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
    // Time Complexity: O(n)
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
    // Time Complexity: O(1)
    void deleteAtStart(){
        if(head!=NULL){
            tail->next=head->next;
            head->next=NULL;
            head=tail->next;
        }

    }
    // Time Complexity: O(n)
    void deleteAtEnd()
    {
        if (head != NULL){
            node *temp=head;
            while(temp->next!=tail)
                temp=temp->next;
            tail->next=NULL;
            tail=temp;
        }

    }
    // Time Complexity: O(n)
    void insertAtanyIndex(int val,int pos){
        node*newNode=new node(val);
        node*temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }
    // Time Complexity: O(n)
    void deleteAtanyIndex(int pos){
        if(pos==0){
            deleteAtStart();
            return;
        }
        else if(head==NULL){
            return;
        }
        else{
            node*temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            return;
        }
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
    cll.insertAtanyIndex(5,2);
    cll.display();
    cout << "Bye Bye" << endl;
    return 0;
}
