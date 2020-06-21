#include "dependence.h"
#include <iostream>

bool InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    return true;
}

bool Full(SqQueue Q)
{
    return ((Q.rear + 1) % MaxSzie == Q.front);
}

bool Empty(SqQueue Q)
{
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType x)
{
    if (Full(Q))
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSzie;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Empty(Q))
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSzie;
    return true;
}

bool GetFront(SqQueue Q, ElemType &x)
{
    if (Empty(Q))
        return false;
    x = Q.data[Q.front];
    return true;
}

int Num(SqQueue Q)
{
    return (Q.rear - Q.front + MaxSzie) % MaxSzie;
}

int