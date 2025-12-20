#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *lChild;
    node *rChild;
    node(int x) : data(x), lChild(nullptr), rChild(nullptr) {}
};
class BST
{
    node *root;
public:
    BST() : root(nullptr) {}
    // insertion
    void insert(int x)
    {
        node *newNode = new node(x);
        if (!root) // empty tree
        {
            root = newNode;
            return;
        }
        node *temp = root;    // that will traverse
        node *back = nullptr; // stop at exact location to where left or right we will insert our node
        while (temp)
        {
            if (newNode->data < temp->data)
            {
                back = temp;
                temp = temp->lChild;
            }
            else if (newNode->data > temp->data)
            {
                back = temp;
                temp = temp->rChild;
            }
            else
            {
                cout << "Duplicate found!!!" << endl;
                continue;
            }
        }
        if (newNode->data < back->data)
        {
            back->lChild = newNode;
        }
        else
        {
            back->rChild = newNode;
        }
    }
    // Deletion
    void deleteNode(int key)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        node *temp = root;
        node *back = nullptr;
        temp=search(key);
        if (temp == nullptr)
        {
            cout << "Key not found" << endl;
            return;
        }
        if (temp->lChild == nullptr && temp->rChild == nullptr) // case:1 Leaf Node
        { 
            if (back == nullptr)
            {
                delete temp; // farig
                root = nullptr;
                return;
            }
            if (back->lChild == temp)
            {
                back->lChild = nullptr;
            }
            else
            {
                back->rChild = nullptr;
            }
            delete temp;
            return;
        }
        if (temp->lChild == nullptr || temp->rChild == nullptr) // case:2 one child node
        {
            node *child = nullptr;
            if (back == nullptr)
            {
                root = child; // node to delete is root
            }
            //find where the node to delete is at LEFT or RIGHT
            if (temp->lChild)
            {
                child = temp->lChild;
            }
            else
            {
                child = temp->rChild;
            }
            // attach child to back
            if (back->lChild == temp)
            {
                back->lChild = child;
            }
            else
            {
                back->rChild = child;
            }
            delete temp;
            return;
        }
        node *suc_back = temp;
        node *suc = temp->rChild;
        while (suc->lChild != nullptr)
        {
            suc_back = suc;
            suc = suc->lChild;
        }
        temp->data = suc->data;
        if (suc_back->lChild == suc)
        {
            suc_back->lChild = suc->rChild;
        }
        else
        {
            suc_back->rChild = suc->rChild;
        }
        delete suc;
    }
    // print functions
    void printInorder()
    {
        node *temp = root;
        inOrder(temp);
        cout << endl;
    }
    void printPreOrder()
    {
        node *temp = root;
        preOrder(temp);
        cout << endl;
    }
    void printPostOrder()
    {
        node *temp = root;
        postOrder(temp);
        cout << endl;
    }
    // Walks
    void inOrder(node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        inOrder(temp->lChild);     // left
        cout << temp->data << ","; // node
        inOrder(temp->rChild);     // right
    }
    void preOrder(node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        cout << temp->data << ","; // node
        preOrder(temp->lChild);    // left
        preOrder(temp->rChild);    // right
    }
    void postOrder(node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        postOrder(temp->lChild);   // left
        postOrder(temp->rChild);   // right
        cout << temp->data << ","; // node
    }
    // utils
    int max()
    {
        node *temp = root;
        while (temp->rChild != nullptr)
        {
            temp = temp->rChild;
        }
        return temp->data;
    }
    int min()
    {
        node *temp = root;
        while (temp->lChild != nullptr)
        {
            temp = temp->lChild;
        }
        return temp->data;
    }
    node *search(int key)
    {
        node *temp = root;
        while (temp)
        {
            if (temp->data == key)
            {
                return temp;
            }
            else if (key < temp->data)
            {
                temp = temp->lChild;
            }
            else
            {
                temp = temp->rChild;
            }
        }
    }
    
};
int main()
{
    BST t1;
    t1.insert(45);
    t1.insert(25);
    t1.insert(20);
    t1.insert(21);
    t1.insert(22);
    t1.insert(35);
    t1.insert(70);
    t1.insert(60);
    t1.insert(80);
    t1.printInorder();
    cout << "Max: " << t1.max() << endl;
    cout << "Min: " << t1.min() << endl;
    t1.deleteNode(70);
    t1.printInorder();
}
