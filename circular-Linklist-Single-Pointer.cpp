#include <iostream>
using namespace std;
// Time complexity: O(n)
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
    // Time Complexity: O(1)
    cLL(){
        head = NULL;
    }
    // Time Complexity: O(n)
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
    // Time Complexity: O(n)
    void insertAtEnd(int val){
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
            // temp = newNode;
            return;
        }
    }
    // Time Complexity: O(n)
    void insertAtanyIndex(int val, int pos)
    {
        if (pos == 0 || head == NULL){
            insertAtStart(val);
            return;
        }
        else if ( pos < 0 || pos > getNodes()){
            return;
        }
        else{
            node *newNode = new node(val);
            node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return;
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
        cout <<" ]"<< endl;
    }
    // Time Complexity: O(n)
    int search(int key){
        if(head==NULL){
            return -1;
        }
        node*temp=head;
        int count=0;
        while(temp->next!=head){
            if(temp->data==key){
                return count;
            }
            temp=temp->next;
            count+=1;
        }
        return -1;
    }
    // Time Complexity: O(n)
    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        return;
    }
    // Time Complexity: O(n)
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        while (temp->next->next != head){
            temp = temp->next;
        }
        temp->next = head;
        return;
    }
    // Time Complexity: O(n)
    void deleteAtanyIndex(int pos){
        if(pos==0){
            deleteAtStart();
            return;
        }
        else if (head == NULL || pos < 0 || pos > getNodes())
        {
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
    // Time Complexity: O(n)
    int getNodes(){
        node*temp=head;
        int count=0;
        while(temp->next!=head){
            count++;
            temp=temp->next;
        }
        return count+1;
    }
    // Time Complexity: O(n)
    void deleteWithData(int val){
        int index=search(val);
        if(index==-1){
            return;
        }
        deleteAtanyIndex(index);
        return;
    }
};
int main()
{
    cLL cl;
    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);
    cl.insertAtEnd(40);
    cl.insertAtStart(10);
    cl.insertAtStart(20);
    cl.insertAtStart(30);
    cl.insertAtStart(40);
    cl.display();
    cout<<cl.getNodes()<<endl;
    // cl.deleteAtStart();
    // cll.deleteAtEnd();
    // cl.deleteAtanyIndex(3);
    cl.display();

    cout << "Bye Bye" << endl;
    return 0;
}
