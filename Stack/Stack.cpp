#include "dependence.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool InitStack(SqStack &S)
{
    S.top = -1;
    return true;
}

bool Empty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSzie - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if (Empty(S))
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, ElemType &x)
{
    if (Empty(S))
        return false;
    x = S.data[S.top];
    return true;
}

bool InitStack_L(SList &SL)
{
    SL = NULL;
}

bool Empty_L(SList SL)
{
    return SL == NULL;
}

bool Push_L(SList &SL, ElemType x)
{
    SNode *p = (SNode *)malloc(sizeof(SNode));
    p->data = x;
    if (SL == NULL)
    {
        SL = p;
    }
    else
    {
        p->next = SL;
        SL = p;
    }
    return true;
}

bool Pop_L(SList &SL, ElemType &x)
{
    if (Empty_L(SL))
        return false;
    x = SL->data;
    SNode *temp = SL;
    SL = temp->next;
    free(temp);
}

