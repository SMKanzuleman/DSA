#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *lChild;
    node *rChild;
    int height;
    node(int x) : data(x), lChild(nullptr), rChild(nullptr), height(0) {}
};

class AVL
{
    node *root;

public:
    AVL() : root(nullptr) {}
    
    AVL(const AVL &other)
    {
        root = copyHelper(other.root);
    }
    
    // wrapper function
    int height()
    {
        return heightHelper(root);
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    node *search(int key)
    {
        node *temp = search(root, key);
        return temp;
    }

    void deleteNode(int key)
    {
        root = delnode(root, key);
    }

    node *copyHelper(node *otherNode)
    {
        if (otherNode == nullptr)
            return nullptr;

        node *newNode = new node(otherNode->data);
        newNode->height = otherNode->height;

        newNode->lChild = copyHelper(otherNode->lChild);
        newNode->rChild = copyHelper(otherNode->rChild);

        return newNode;
    }
    
    // Helper functions
    int heightHelper(node *temp)
    {
        if (!temp)
        {
            return -1;
        }
        return temp->height;
    }

    int balanceFactor(node *temp)
    {
        if (!temp)
        {
            return 0;
        }
        return heightHelper(temp->lChild) - heightHelper(temp->rChild);
    }

    node *search(node *temp, int key)
    {
        if (!temp)
            return nullptr;
        if (temp->data == key)
            return temp;
        if (key < temp->data)
            return search(temp->lChild, key);
        else
            return search(temp->rChild, key);
    }

    node *insert(node *temp, int key)
    {
        if (!temp)
            return new node(key);
        if (key < temp->data)
        {
            temp->lChild = insert(temp->lChild, key);
        }
        else if (key > temp->data)
        {
            temp->rChild = insert(temp->rChild, key);
        }
        else
        {
            return temp;
        }
        // update height
        temp->height = 1 + max(heightHelper(temp->lChild), heightHelper(temp->rChild));

        int bf = balanceFactor(temp);
        // RR
        if (bf < -1 && key > temp->rChild->data)
            return leftRotate(temp);
        // RL
        if (bf < -1 && key < temp->rChild->data)
        {
            temp->rChild = rightRotate(temp->rChild);
            return leftRotate(temp);
        }
        // LL
        if (bf > 1 && key < temp->lChild->data)
        {
            return rightRotate(temp);
        }
        // LR
        if (bf > 1 && key > temp->lChild->data)
        {
            temp->lChild = leftRotate(temp->lChild);
            return rightRotate(temp);
        }
        return temp;
    }

    node *delnode(node *temp, int key)
    {
        if (!temp)
            return nullptr;
        // Traverse the tree
        if (key < temp->data)
        {
            temp->lChild = delnode(temp->lChild, key);
        }
        else if (key > temp->data)
        {
            temp->rChild = delnode(temp->rChild, key);
        }
        else//temp ko to exact that index we want to delete valeu
        {
            // Case 1 & 2: node has 0 or 1 child
            if (temp->lChild == nullptr || temp->rChild == nullptr)
            {
                node *child = temp->lChild ? temp->lChild : temp->rChild;
                if (child == nullptr) //: node has 0 child
                { 
                    delete temp;
                    return nullptr;
                }
                else //: node has 1 child
                { 
                    *temp = *child;
                    delete child;
                }
            }
            else//2 child
            {
                node *is = min(temp->rChild);
                temp->data = is->data;
                temp->rChild = delnode(temp->rChild, is->data);
            }
        }
        if (!temp)
            return temp;
        // update height
        temp->height = 1 + max(heightHelper(temp->lChild), heightHelper(temp->rChild));
        int bf = balanceFactor(temp);
        // RR
        if (bf < -1 && balanceFactor(temp->rChild) <= 0)
            return leftRotate(temp);
        // RL
        if (bf < -1 && balanceFactor(temp->rChild) > 0)
        {
            temp->rChild = rightRotate(temp->rChild);
            return leftRotate(temp);
        }
        // LL
        if (bf > 1 && balanceFactor(temp->lChild) >= 0)
        {
            return rightRotate(temp);
        }
        // LR
        if (bf > 1 && balanceFactor(temp->lChild) < 0)
        {
            temp->lChild = leftRotate(temp->lChild);
            return rightRotate(temp);
        }
        return temp;
    }
    
    // Utility functions
    node *leftRotate(node *x)
    {
        node *y = x->rChild;
        node *t2 = y->lChild;
        // rotation
        y->lChild = x;
        x->rChild = t2;

        x->height = 1 + max(heightHelper(x->lChild), heightHelper(x->rChild));
        y->height = 1 + max(heightHelper(y->lChild), heightHelper(y->rChild));

        return y;
    }
    
    node *rightRotate(node *x)
    {
        node *y = x->lChild;
        node *t2 = y->rChild;
        // rotate
        y->rChild = x;
        x->lChild = t2;

        x->height = 1 + max(heightHelper(x->lChild), heightHelper(x->rChild));
        y->height = 1 + max(heightHelper(y->lChild), heightHelper(y->rChild));

        return y;
    }
    
    void inOrder(node *temp)
    {
        if (!temp)
            return;
        inOrder(temp->lChild); // L
        cout << temp->data << ", ";
        inOrder(temp->rChild);
    }
    
    void print()
    {
        inOrder(root);
        cout << endl;
    }
    
    node* min(node *root)
    {
        node *temp = root;
        while (temp->lChild != nullptr)
        {
            temp = temp->lChild;
        }
        return temp;
    }
};

int main()
{
    AVL t1;
    t1.insert(30);
    t1.insert(20);
    t1.insert(40);
    t1.insert(50);
    t1.print();
    cout << t1.height() << endl;
    cout<<"balancing factor of root: "<<t1.balanceFactor(t1.search(30))<<endl;
    t1.deleteNode(20);
    t1.print();
    cout<<t1.height()<<endl;
    cout<<"balancing factor of root: "<<t1.balanceFactor(t1.search(30))<<endl;
    return 0;
    //"https://d.docs.live.net/47ED0824130BFC11/Documents/Shajra.xlsx"
}
