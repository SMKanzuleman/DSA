#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value){
        this->data = value;
        this->next = NULL;
    }
    node(){
        this->next = NULL;
    }
};
class cLL
{
    node *head;
public:
    cLL(){
        head = NULL;
    }
    void insertAtStart(int val){
        node *newNode = new node(val);
        if (head == NULL){
            head = newNode;
            head->next = newNode;
            return;
        }
        else{
            node*temp=head;
            while(temp->next!=head)
                temp=temp->next;
            newNode->next=temp->next;
            temp->next=newNode;
            head=newNode;
            return;
        }
    }
    void insertAtEnd(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head=newNode;
            head->next=newNode;
            return;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode;
            return;
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
        cout <<" ]"<< endl;
    }
};
int main()
{
    cLL cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    // cll.insertAtStart(10);
    // cll.insertAtStart(20);
    // cll.insertAtStart(30);
    // cll.insertAtStart(40);
    cll.display();
    cout << "Bye Bye" << endl;
    return 0;
}