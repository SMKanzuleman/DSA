//SinglyLinkList
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        next=NULL;
    }
    node(int a){
        data=a;
        next=NULL;
    }
};

class list{
    node*head;
    public:
    list(){
        head=NULL;
    }
    //Time Complexity O(1)
    void insertStart(int val){
        node* newNode = new node(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }
    //Time Complelxity O(n)
    void insertEnd(int val){
        node* newNode = new node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else{
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
            return;
        }

    }
   // Time Complexity O(n)
    void insertAtAnyIndex(int val,int pos){
        if (pos == 0 || head==NULL)
        {
            insertStart(val);
            return;
        }
        else if(pos>getnodes()){
            return;
        }
        else{
            node* newNode = new node(val);
            node*temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    // Time Complexity O(n)
    void display(){
        if(head==NULL){
            return;
        }
        else{
            node *temp = head;
            cout<<"[ ";
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL)
                    cout << ",";
            }
            cout<<" ]"<< endl;
        }

    }
    // Time Complexity O(n)
    int getnodes(){
        node*temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    // Time Compexity O(n)
    int search(int val){
        node*temp=head;
        int index=0;
        while(temp!=NULL){
            if(temp->data==val){
                    return index;
            }
            index++;
            temp=temp->next;
        }
        return -1;
    }
     // Time Complexity O(1) for best case, O(n) for worst case
    void deleteAtStart(){
        if(head == NULL){
            return;
        }
        else{
            node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
    }
    // Time Complexity O(n)
    void deleteAtEnd(){
        if(head==NULL){
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        else{
            node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
    // Time Complexity O(n)
    void deleteAtAnyIndex(int pos){
        if(head==NULL || pos<0 || pos >= getnodes()){
            return;
        }
        else if(pos==0){
            deleteAtStart();
            return;
        }
        else
        {
            node *temp = head;
            for (int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            node *toDelete = temp->next;
            temp->next=toDelete->next;
            delete toDelete;
            return;
        }
    }
    // Time Complexity O(n)
    void deleteWithData(int val){
        int a = search(val);
        if (a != -1) {
            deleteAtAnyIndex(a);
            return;
        }
        else{
            return;
        }
    }
   // Time Complexity O(n)
    node* mid(){
        if(head==NULL){
            return nullptr;
        }
        node* fastptr=head;
        node* slowptr=head;
        while (fastptr != NULL && fastptr->next->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
    }
    // Time Complexity O(n)
    void reverse(){
        if(head==nullptr){
            return;
        }
        else{
            node*temp=head;
            node*prev=nullptr;
            node*next=nullptr;
            while (temp != NULL)
            {
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
            }
            head=prev;
            return;
        }
    }
};

int main() {
    list l1;
    l1.insertStart(55);
    l1.insertEnd(65);
    l1.insertEnd(75);
    l1.insertEnd(95);
    l1.display();
    l1.reverse();
    l1.display();
     node* midNode = l1.mid();
     if(midNode != NULL) {
         cout << "Mid element is " << midNode->data << endl;
     }
     l1.deleteAtEnd();
     l1.display();
     cout<<"Found at index "<<l1.search(65) << endl;
     l1.deleteWithData(65);
     l1.display();
     return 0;
}