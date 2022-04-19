#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int value;
    node* pnext;
};

struct list
{
    node* pHead;
    node* pTail;
};

//them, xoa, sua
void addtail(list* ls, int a)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->pnext = NULL;
    newnode->value = a;
    if (ls->pHead == NULL)
        ls->pHead = newnode;
    if (ls->pTail != NULL)
        ls->pTail->pnext = newnode;
    ls->pTail = newnode;
}
void addhead(list* ls, int a)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->pnext = NULL;
    newnode->value = a;

    if (ls->pHead == NULL)
        ls->pHead = ls->pTail = newnode;
    else
    {
        newnode->pnext = ls->pHead;
        ls->pHead = newnode;
    }
}
void removehead(list* ls)
{
    if (ls->pHead == NULL)//Ko có phần tử
        return;
    if (ls->pHead == ls->pTail)//Có 1 phần tử
    {
        free(ls->pHead);
        ls->pHead = ls->pTail = NULL;
        return;
    }
    //2 phần tử trở lên
    node* temp = ls->pHead;
    ls->pHead = ls->pHead->pnext;
    free(temp);
}
void removetail(list* ls)
{
    if (ls->pTail == NULL)//Ko có phần tử
        return;
    if (ls->pHead == ls->pTail)//Có 1 phần tử
    {
        free(ls->pHead);
        ls->pHead = ls->pTail = NULL;
        return;
    }
    //2 phần tử trở lên
    node* temp = ls->pTail;
    node* i = ls->pHead;
    while (i->pnext != ls->pTail)
    {
        i = i->pnext;
    }
    ls->pTail = i;
    ls->pTail->pnext = NULL; //Quan trọng
    free(temp);
}
//print danh sach 
void printlist(list* ls)
{
    node* i = ls->pHead;
    while (i != NULL)
    {
        printf("%d ", i->value);
        i = i->pnext;
    }
    printf("\n");
}


int main()
{
    //Tạo thử list1
    list* ls = (list*)malloc(sizeof(list));
    ls->pHead = ls->pTail = NULL;
    addtail(ls, 1);
    addtail(ls, 2);
    addtail(ls, 3);
    addtail(ls, 5);
    addtail(ls, 5);
    addtail(ls, 5);
    addtail(ls, 9);
    printlist(ls);

    for (int i = 0; i < 8; i++)
    {
        removehead(ls);
        printlist(ls);
    }

    //Tạo thử list2
    list* ls2 = (list*)malloc(sizeof(list));
    ls2->pHead = ls2->pTail = NULL;
    addhead(ls2, 1);
    addhead(ls2, 2);
    addhead(ls2, 3);
    addhead(ls2, 5);
    addhead(ls2, 5);
    addhead(ls2, 5);
    addhead(ls2, 9);
    printlist(ls2);
    for (int i = 0; i < 8; i++)
    {
        removetail(ls2);
        printlist(ls2);
    }
    return 0;
}