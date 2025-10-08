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
    void insertStart(node* val){
        if(head!=NULL){
            val->next=head;
            head=val;
        }
        else
            head=val;
    }
    void insertEnd(node* val){
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=val;
        val->next=NULL;
    }
    void insert(node* val,int pos){
        if (pos == 0 || head==NULL)
        {
            insertStart(val);
            return;
        }
        else if(pos>getnodes()){
            return ;

        }
        else if(head!=NULL){
            node*temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            val->next=temp->next;
            temp->next=val;
        }
    }
    void display(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" , ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int getnodes(){
        node*temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    int search(node* val){
        node*temp=head;
        int index=0;
        while(temp!=NULL){
            if(temp->data==val->data){
                    return index;
            }
            index++;
            temp=temp->next;
        }
        return -1;
    }
    void delStart(){
        if(head!= NULL){    
            node*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        return;
    }
    void delEnd(){
        if(head==NULL){
            return;
        }
        if (head->next == NULL)
        { // Case 2: Only one node

            head = NULL;
            return;
        }
        // if(head!=NULL){      
            node*temp=head;
            while(temp->next->next!=NULL)
                temp=temp->next;
            temp->next=NULL;

    }
    void deletek(int pos){
        if(head==NULL || pos<0 || pos >= getnodes()){
            return;
        }
        if(pos==0){
            delStart();
            return;
        }
        node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        node *aa = temp->next;
        temp->next = aa->next;
        delete aa;
    }
    void sd(node* val){
        int a=search(val);
        deletek(a);
    }
    void mid(){
        node* fastptr=head;
        node* slowptr=head;
        int count=0;
        // while(fastptr->next!=NULL){
        //     slowptr=slowptr->next;
        //     count++;
        //     fastptr=fastptr->next;
        //     if (fastptr->next != NULL){
        //         fastptr=fastptr->next;
        //     }
        // }
        while (fastptr != NULL && fastptr->next->nex != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        cout<<slowptr->data;
    }
};

int main() {
    list l1;
    node *aa=new node(55);
    node *bb=new node(65);
    node *cc=new node(75);
    node *dd=new node(95);
    l1.insertStart(aa);
    l1.insertEnd(bb);
    l1.insertEnd(cc);
    l1.insertEnd(dd);
    l1.display();
    l1.mid();
    // l1.delEnd();
    // l1.display();
    // cout<<"Found at index "<<l1.search(dd);
    return 0;
}