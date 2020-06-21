#include "dependence.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool InitList(LinkList &H)
{
    H = (LNode *)malloc(sizeof(LNode));
    if (H == NULL)
        return false; //内存不足
    else
    {
        H->next = NULL;
        return true;
    }
}

bool Empty(LinkList H)
{
    return H->next == NULL;
}

LNode *GetNode(LinkList H, int i)
{
    if (i < 0)
        return NULL;
    int count = 0;
    LNode *term = H;
    while (term != NULL && count++ < i)
        term = term->next;
    return term;
}

LNode *LocateNode(LinkList H, ElemType e)
{
    LNode *p = H->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

int Length(LinkList H)
{
    int len = 0;
    LNode *p = H->next;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *term = (LNode *)malloc(sizeof(LNode));
    if (term == NULL)
        return false;
    term->data = e;
    term->next = p->next;
    p->next = term;
    return true;
}

// 后插入一个结点，将此节点的内容和p交换内容，实现前插入
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *term = (LNode *)malloc(sizeof(LNode));
    term->next = p->next;
    p->next = term;
    std::swap(p->data, term->data);
    return true;
}

bool Insert(LinkList &H, int i, ElemType e)
{
    LNode *p = GetNode(H, i - 1);
    if (p == NULL)
        return false;
    return InsertNextNode(p, e);
}

bool Delete(LinkList &H, int i, ElemType &e)
{
    LNode *p = GetNode(H, i - 1);
    if (p == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    if (p->next != NULL)
    {
        LNode *q = p->next;
        std::swap(q->data, p->data);
        p->next = q->next;
        free(q);
        return true;
    }
    else
    {
        cout << "can't use this function at the end of List." << endl;
        return false;
    }
}

bool Creat_Tail(LinkList &H, int A[], int n)
{
    if (!InitList(H))
        return false;
    LNode *temp, *r;
    temp = r = H;
    for (int i = 0; i < n; i++)
    {
        temp = (LNode *)malloc(sizeof(LNode));
        temp->data = A[i];
        r->next = temp;
        r = r->next;
    }
    r->next = NULL;
    return true;
}

// 可用于单链表逆置
bool Creat_Head(LinkList &H, int A[], int n)
{
    if (!InitList(H))
        return false;
    LNode *temp;
    for (int i = 0; i < n; i++)
    {
        temp = (LNode *)malloc(sizeof(LNode));
        temp->data = A[i];
        temp->next = H->next;
        H->next = temp;
    }
    return true;
}

int main()
{
}