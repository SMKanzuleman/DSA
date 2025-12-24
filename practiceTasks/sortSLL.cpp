#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x) : data(x), next(nullptr) {};
};
class SLL
{
    node *head;
    public:
    SLL() : head(nullptr) {}
    node *getmiddle(node *head)
    {
        node *slow = head;
        node *fast = head->next;//slow stop befor mid to avoid infinite loop
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void insert(int value)
    {
        node *newNode = new node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }
    void print()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << ",";
            temp = temp->next;
        }
    }
    node*merg(node*left,node*right){
        //base cases
        if(!left) return right;
        if(!right) return left;

        node*merged=nullptr;

        //comparing
        if(left->data<right->data){
            merged=left;
            merged->next=merg(left->next,right);
        }
        else{
            merged=right;
            merged->next=merg(left,right->next);
        }
        return merged;
    }
    node*getHead(){
        return this->head;
    }
    void setHead(node*temp){
        head=temp;
    }
    node *mergSort(node *head)
    {
        // base case
        if (!head || !head->next)
            return head;
        node *m = getmiddle(head);
        node *j = m->next;
        // Break the Link--divide into two halves
        m->next = nullptr;
        //sort both parts Recursively
        node*left=mergSort(head);
        node*right=mergSort(j);
        //merg sorted parts;
        node*sortedlist=merg(left,right);

        return sortedlist;
    }
    void mergSort(){
        head=mergSort(head);
    }
};

int main()
{
    SLL l1;
    l1.insert(25);
    l1.insert(18);
    l1.insert(12);
    l1.insert(15);
    l1.insert(10);
    l1.print();
    cout<< "\nSorted:" << endl;
    l1.mergSort();    
    l1.print();
    return 0;
}