#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int value;
    node* pNext;
};

typedef struct list queue;
struct list
{
    node* pHead;
    node* pTail;
};

bool IsEmpty(queue* q)
{
    if (q->pHead == NULL && q->pTail == NULL)
        return true;
    else
        return false;
}

void initqueue(queue* q)
{
    q->pHead = q->pTail = NULL;
}


void enqueue(queue* q, int value)
{
    node* newnode = new node;
    newnode->value = value;
    newnode->pNext = NULL;
    //add tail
    if (q->pHead == NULL)
        q->pHead = q->pTail = newnode;
    else
    {
        q->pTail->pNext = newnode;
        q->pTail = newnode;
    }
}

node* dequeu(queue* q)
{
    node* getme;
    //get from head
    if (q->pHead == NULL)
        return NULL;
    if (q->pHead == q->pTail)
    {
        getme = q->pHead;
        q->pHead = q->pTail = NULL;
        return getme;
    }
    else
    {
        getme = q->pHead;
        q->pHead = q->pHead->pNext;
        return getme;
    }

}


void printqueue(queue* q)
{
    node* i = q->pHead;
    while (i != NULL)
    {
        cout << i->value << " ";
        i = i->pNext;
    }
    cout << endl;
}

int main()
{
    queue* q1 = new queue;
    initqueue(q1);

    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    printqueue(q1);

    dequeu(q1);
    printqueue(q1);
    dequeu(q1);
    printqueue(q1);

    delete q1;

    return 0;
}