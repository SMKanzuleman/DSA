/*
 =======================================================================
 Description:
 =======================================================================
*/

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class dLL
{
    node *head;
    node *tail;

public:
    dLL()
    {
        head = tail = NULL;
    }
    // Time Complexity O(1)
    void insertAtHead(int val)
    {
        node *newNode = new node(val);
        if (head != NULL)
        {
            tail->next = newNode;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail = newNode;
            return;
        }
        else
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
    }
    // Time Complexity O(1)
    void insertAtEnd(int val)
    {
        node *newNode = new node(val);
        if (head != NULL)
        {
            newNode->next = head;
            tail->next = newNode;
            newNode->prev = tail;
            head->prev = newNode;
            tail = newNode;
            return;
        }
        else
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
    }
    // Time Complexity O(n)
    void insertAtIndex(int val, int pos)
    {
        node *newNode = new node(val);
        if (head != NULL)
        {
            // if there is only 1 element
            if (pos == 0)
            {
                insertAtHead(val);
                return;
            }
            // if user want to insert at end
            if (pos == getnodes())
            {
                insertAtEnd(val);
                return;
            }
            // invalid index case
            if (pos > getnodes() || pos < 0)
            {
                return;
            }
            // at any index code
            node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }
        else
        {
            head = newNode;
            return;
        }
    }
    // Time Complexity O(n)
    int getnodes()
    {
        if (head != NULL)
        {
            int count = 0;
            node *temp = head;
            do
            {
                temp = temp->next;
                count++;
            } while (temp != head);
            return count;
        }
        else
        {
            return -1;
        }
    }
    // Time Complexity O(n)
    void display()
    {
        if (head != NULL)
        {
            node *temp = head;
            do
            {
                cout << temp->data << ",";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
    // Time Complexity O(1)
    void delAtStart()
    {
        if (head != NULL)
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
                return;
            }
            node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        else
        {
            return;
        }
    }
    // Time Complexity O()
    void delAtEnd()
    {
        if (head != NULL)
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
                return;
            }
            node *newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            tail = newTail;
        }
        else
        {
            return;
        }
    }

    void delAtIndex(int pos)
    {
        int total=getnodes()-1;
        if (head != NULL)
        {
            if (pos == 0)
            {
                delAtStart();
                return;
            }
            else if (pos == total)
            {
                delAtEnd();
                return;
            }
            else if (pos < 0 || pos > total)
            {
                return;
            }
            else
            {
                node *temp = head;
                for (int i = 0; i < pos; i++)
                {
                    temp = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
        }
    }
};

int main()
{

    dLL a1;
    a1.insertAtHead(1);
    a1.insertAtHead(2);
    a1.insertAtHead(3);
    a1.insertAtHead(4);
    a1.insertAtHead(5);
    a1.insertAtEnd(6);
    a1.insertAtEnd(7);
    a1.insertAtEnd(8);
    a1.insertAtEnd(9);
    a1.display();
    a1.delAtIndex(8);
    a1.display();
    cout << "Hi KanzulEman" << endl;
    return 0;
}