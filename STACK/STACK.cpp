#include <iostream>
using namespace std;

typedef struct node node;
struct node
{
    int value;
    node* pNext;
};

typedef struct list stack;
struct list
{
    node* pHead;
    node* pTail;
};

bool isEmpty(stack* s)
{
    if (s->pHead == NULL && s->pTail == NULL)
        return true;
    return false;
}

void push(stack* s, int value)
{
    node* newnode = new node;
    newnode->pNext = NULL;
    newnode->value = value;

    if (s->pHead == NULL)
    {
        s->pHead = s->pTail = newnode;
    }
    else
    {
        s->pTail->pNext = newnode;
        s->pTail = newnode;
    }
}


node* pop(stack* s)
{
    node* getme;
    if (s->pTail == NULL)
        return NULL;
    if (s->pHead == s->pTail)
    {
        getme = s->pTail;
        s->pHead = s->pTail = NULL;
    }
    else
    {
        node* i = s->pHead;
        while (i->pNext != s->pTail)
        {
            i = i->pNext;
        }
        getme = s->pTail;
        s->pTail = i;
        s->pTail->pNext = NULL;
    }
    return getme;
}


void printstack(stack* s)
{
    node* i = s->pHead;
    while (i != NULL)
    {
        cout << i->value << " ";
        i = i->pNext;
    }
    cout << endl;
}


int main()
{
    stack* s = new stack;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    printstack(s);

    pop(s);
    pop(s);
    printstack(s);
    delete s;
    return 0;
}