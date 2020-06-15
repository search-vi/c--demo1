#include "dependence.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool InitDLinkList(DLinkList &H)
{
    H = (DNode *)malloc(sizeof(DNode));
    if (H == NULL)
        return false;
    H->next = H->piror = NULL;
    return true;
}

bool InsertNextNode(DNode *p, DNode *q)
{
    if (p == NULL || q == NULL)
        return false;
    q->next = p->next;
    if (p->next != NULL)
        p->next->piror = q;
    p->next = q;
    q->piror = p;
    return true;
}

bool DeleteNextNode(DNode *p)
{
    if (p == NULL || p->next == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->piror = p;
    free(q);
    return true;
}

void DestoryList(DLinkList &L)
{
    while (L->next != NULL)
        DeleteNextNode(L);
    free(L);
    L = NULL;
}
