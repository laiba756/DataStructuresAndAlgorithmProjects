#include<iostream>
using namespace std;
class Node {
private:
    Node* parent;
    Node* left;
    Node* right;
    int val;
public:
    Node() {
        val = -1;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    Node(int v) {
        val = v;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    void setparent(Node* p) {
        parent = p;
    }
    Node* getparent() {
        return parent;
    }
    void setleft(Node* l) {
        left = l;
    }
    Node* getleft() {
        return left;
    }
    void setright(Node* r) {
        right = r;
    }
    Node* getright() {
        return right;
    }
    void setval(int v)
    {
        val = v;
    }
    int getval()
    {
        return val;
    }

};

class BST
{
public:
    Node* root;
    BST()
    {
        this->root = NULL;

    }
    void insert(int v)
    {
        Node* p = root,
            * prev = 0;
        while (p != 0 && root != 0)
        {

            prev = p;
            if (v < p->getval())
                p = p->getleft();
            else
                p = p->getright();
        }
        if (root == 0)
            root = new Node(v);
        else if (v < prev->getval())
        {
            Node* temp = new Node(v);
            temp->setparent(prev);
            prev->setleft(temp);
        }
        else {
            Node* temp = new Node(v);
            temp->setparent(prev);
            prev->setright(temp);
        }
    }
    void preorder(Node* BSTNode)
    {
        if (BSTNode != NULL)
        {
            cout << BSTNode->getval() << " ";
            preorder(BSTNode->getleft());
            preorder(BSTNode->getright());
        }
    }
    void postorder(Node* BSTNode)
    {
        if (BSTNode != NULL)
        {
            postorder(BSTNode->getleft());
            postorder(BSTNode->getright());
            cout << BSTNode->getval() << " ";
        }
    }
    void inorder(Node* BSTNode)
    {
        if (BSTNode != NULL)
        {
            inorder(BSTNode->getleft());
            cout << BSTNode->getval() << " ";
            inorder(BSTNode->getright());
        }
    }
    Node* findMin(Node* Node)
    {
        if (Node == NULL)
            return NULL;
        if (Node->getleft() == NULL)
            return Node;
        return findMin(Node->getleft());
    }
    Node* findMax(Node* Node)
    {
        if (Node == NULL)
            return NULL;
        if (Node->getright() == NULL)
            return Node;
        return findMax(Node->getright());
    }
    bool search(int v)
    {
        Node* p = root;
        while (p != 0)
        {
            if (v == p->getval())
                return true;
            else if (v < p->getval())
                p = p->getleft();
            else
                p = p->getright();
        }
        return 0;
    }
    Node* remove(Node* tree, int v)
    {
        Node* t;
        int cmp = v - tree->getval();
        if (cmp < 0)
        {
            t = remove(tree->getleft(), v);
            tree->setleft(t);
            if (t != NULL)
                t->setparent(tree);
        }
        else if (cmp > 0)
        {
            t = remove(tree->getright(), v);
            tree->setright(t);
            if (t != NULL)
                t->setparent(tree);
        }
        // two children, replace with inorder successor
        else if (tree->getleft() != NULL && tree->getright() != NULL)
        {
            Node* minNode;
            minNode = findMin(tree->getright());
            tree->setval(minNode->getval());
            t = remove(tree->getright(),
                minNode->getval());
            tree->setright(t);
            if (t != NULL) // updating parent
                t->setparent(tree);
        }
        else
        {
            Node* nodeToDelete = tree;
            if (tree->getleft() == NULL) //if 0 children
                tree = tree->getright();
            else if (tree->getright() == NULL)
                tree = tree->getleft();
            else
                tree = NULL;

            delete nodeToDelete;
        }
        return tree;
    }
};
int main() {
    cout << "BINARY SEARCH TREES" << endl;
    BST b;
    b.insert(44);
    b.insert(87);
    b.insert(23);
    b.insert(74);
    b.insert(83);
    cout << endl << endl;
    cout << "Pre Order" << endl;
    b.preorder(b.root);
    cout << endl << endl;
    cout << "Post Order" << endl;
    b.postorder(b.root);
    cout << endl << endl;
    cout << "In Order" << endl;
    b.inorder(b.root);
    cout << endl << endl;

    cout << "MIN: " << b.findMin(b.root)->getval() << endl;
    cout << "MAX: " << b.findMax(b.root)->getval() << endl << endl;
    cout << "SEARCHING AN ELEMENT:" << endl;
    b.search(37) ? cout << "Yes, Searched element is present in tree" << endl : cout << "Ele not found in tree" << endl << endl;
    cout << "DELETION OF ELEMENTS:" << endl;
    cout << "In-order Traversal after Deleting node with value 74 in the tree " << endl;
    b.remove(b.root, 74);
    b.preorder(b.root);
    return 0;
}



