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

public:
    dLL()
    {
        head = NULL;
    }
    // Time Complexity O(1)
    void insertAtHead(int val)
    {
        node *newNode = new node(val);
        if (head != NULL)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        else
        {
            head = newNode;
            return;
        }
    }
    // Time Complexity O(n)
    void insertAtEnd(int val)
    {
        node *newNode = new node(val);
        if (head != NULL)
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
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
            while (temp != NULL)
            {
                temp = temp->next;
                count++;
            }
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
            while (temp != NULL)
            {
                cout << temp->data << ",";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    // Time Complexity O(1)
    void delAtStart()
    {
        if (head != NULL)
        {
            node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            return;
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
            if (head->next == NULL)
            {
                head = NULL;
                return;
            }
            else
            {
                node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->prev->next = NULL;
                delete temp;
            }
        }
    }

    void delAtIndex(int pos)
    {
        if (head != NULL)
        {
            if (pos == 0)
            {
                delAtStart();
                return;
            }
            else if (pos == getnodes() - 1)
            {
                delAtEnd();
                return;
            }
            else if (pos < 0 || pos > getnodes() - 1)
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
                temp->next = NULL;
                temp->prev = NULL;
                delete temp;
                return;
            }
        }
    }
};

int main()
{

    dLL a1;
    a1.insertAtEnd(2);
    a1.insertAtEnd(8);
    a1.insertAtIndex(15, 2);
    a1.display();
    a1.delAtIndex(2);
    a1.display();
    cout << "Hi KanzulEma" << endl;
    return 0;
}