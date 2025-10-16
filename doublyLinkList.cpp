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
    // Time Complexity: O(1)
    dLL()
    {
        head = NULL;
    }
    // Time Complexity: O(1)
    void insertAtStart(int val)
    {
        node *newNode = new node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head=newNode;
        }
 
    }
    // Time Complexity: O(n)
    void insertAtEnd(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    }
    // Time Complexity: O(n)
    void disply(){
        node*temp=head;
        cout<<"[ ";
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<",";
            }
        }
        cout<<" ]"<<endl;
    }
    // Time Complexity: O(1)
    void deleteAtStart(){
        if(head==NULL){
            return;
        }
        else{
            node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }
    // Time Complexity: O(n)
    void deleteAtEnd(){
        if(head==NULL){
            return;
        }
        else{
            node*temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
        }
    }
    // Time Complexity: O(n)
    int search(int key){
        if(head==NULL){
            return -1;
        }
        else{
            node*temp=head;
            int count=0;
            while(temp!=NULL){
                if(key==temp->data){
                    return count;
                }
                count++;
                temp=temp->next;
            }
            return -1;
        }
    }
    // Time Complexity: O()
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
    //**************************************************************** */
    //                  Utility Functions
    //**************************************************************** */
    void ifelse(int val){
        int index=search(val);
        if(index==-1){
            cout<<"Piyary Bhai Element Nai Milla."<<endl;
        }
        else{
            cout << "Piyary Bhai Element Found at "<<index<<" index."<<endl;
        }
    }
};
int main(){
    dLL dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(12);
    dll.insertAtStart(3);
    dll.insertAtEnd(4);
    dll.insertAtStart(5);
    dll.insertAtEnd(7);
    dll.disply();
    dll.ifelse(7);
    return 0;
}