#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
};
class list
{
    node *head;
    node *tail;

public:
    list()
    {
        head = tail=NULL;
    }
    void pushFront(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pushBack(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void popFront()
    {
        if (head == NULL)
        {
            return;
        }
        else{
            node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void popBack()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
        }
    }
    void insert(int val,int pos){
        if(pos==0){
            pushFront(val);
        }
        else{
            node*temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            node*newNode=new node(val);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    int search(int key){
        node*temp=head;
        int ind=0;
        while(temp->next!=NULL){
            if(temp->data==key){
                return ind;
            }
            temp=temp->next;
            ind++;
        }
    }
    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<",";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    list l1;
    l1.pushFront(5);
    l1.pushFront(6);
    l1.pushFront(9);
    l1.pushBack(3);
    l1.pushBack(10);
    l1.pushBack(56);
    l1.print();
    l1.insert(25,3);
    l1.print();
    cout<<l1.search(25);
    cout << "Bye Bye" << endl;
    return 0;
}
//kanzuleman