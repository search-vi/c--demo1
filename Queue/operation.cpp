#include "dependence.h"

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

bool DeQueue(SqQueue &Q, )