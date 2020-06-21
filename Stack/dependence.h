#define MaxSzie 100
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSzie];
    int top;
} SqStack;

typedef struct SNode
{
    ElemType data;
    struct SNode *next;
} SNode, *SList;
