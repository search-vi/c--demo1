typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *next;
    struct DNode *piror;
} DNode, *DLinkList;
