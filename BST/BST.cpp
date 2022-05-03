// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BST
{
private:
    struct node
    {
        int m_value;
        struct node* pLeft, * pRight;
    };
    node* m_root;
public:
    BST() { m_root = NULL; }
    BST(int data)
    {
        m_root->m_value = data;
        m_root->pLeft = m_root->pRight = NULL;
    }
    node*& getRootNode() { return m_root; }
    int getRootValue() { return m_root->m_value; }

    void traversal(node* t)
    {
        if (t == NULL)
            return;
        traversal(t->pLeft);
        cout << t->m_value << " ";
        traversal(t->pRight);
    }

    int Minvalue(node* t)
    {
        if (t == NULL)
            return INT_MAX;//Tree without node
        if (t->pLeft == NULL)//node left
            return t->m_value;
        return Minvalue(t->pLeft);
    }

    node* insert(const int& value, node*& t) //Lưu ý ref para &t
    {
        if (t == NULL)//first node
        {
            node* newnode = new node;
            newnode->m_value = value;
            newnode->pLeft = newnode->pRight = NULL;
            t = newnode;
            return newnode;
        }

        if (value >= t->m_value)
            return insert(value, t->pRight);
        else
            return insert(value, t->pLeft);
    }
};

int main()
{
    BST* tree = new BST();
    tree->insert(7, tree->getRootNode());
    tree->insert(4, tree->getRootNode());
    tree->insert(12, tree->getRootNode());
    tree->insert(3, tree->getRootNode());
    tree->insert(5, tree->getRootNode());
    tree->insert(9, tree->getRootNode());
    tree->insert(13, tree->getRootNode());
    tree->insert(1, tree->getRootNode());
    tree->traversal(tree->getRootNode());
    cout << "Min value tree1:" << tree->Minvalue(tree->getRootNode()) << endl;


    BST* tree2 = new BST();
    tree2->insert(1, tree2->getRootNode());
    tree2->insert(3, tree2->getRootNode());
    tree2->insert(4, tree2->getRootNode());
    tree2->insert(5, tree2->getRootNode());
    tree2->insert(7, tree2->getRootNode());
    tree2->insert(9, tree2->getRootNode());
    tree2->insert(12, tree2->getRootNode());
    tree2->insert(13, tree2->getRootNode());
    tree2->traversal(tree2->getRootNode());
    cout << "Min value tree2:" << tree2->Minvalue(tree2->getRootNode()) << endl;

    BST* tree3 = new BST();
    tree3->insert(30, tree3->getRootNode());
    tree3->insert(19, tree3->getRootNode());
    tree3->insert(48, tree3->getRootNode());
    tree3->insert(12, tree3->getRootNode());
    tree3->insert(15, tree3->getRootNode());
    tree3->insert(36, tree3->getRootNode());
    tree3->insert(50, tree3->getRootNode());
    tree3->traversal(tree3->getRootNode());
    cout << "Min value tree3:" << tree3->Minvalue(tree3->getRootNode()) << endl;


    delete tree, tree2, tree3;
    return 0;
}
