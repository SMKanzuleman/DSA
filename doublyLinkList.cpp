#include <iostream>
using namespace std;
// Time complexity: O(n)
// DoublyLinkList
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
    node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
};
class dLL
{
    node *head;

public:
    dLL()
    {
        head = NULL;
    }
    void insertAtStart(int val)
    {
        node *newNode = new node(val);
        newNode->next = head;
        head->prev = newNode;
 
    }
    void disply(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" , ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtAnyIndex(int val,int pos){
        // if(head!=NULL){
            node*newNode=new node(val);
            node*temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
        }
    // }
};
int main(){
    dLL dll;
    dll.insertAtAnyIndex(2,0);
    dll.insertAtAnyIndex(3,1);
    dll.insertAtAnyIndex(4,2);
    dll.insertAtAnyIndex(5,3);
    dll.insertAtAnyIndex(6,4);
    dll.disply();
    return 0;
}