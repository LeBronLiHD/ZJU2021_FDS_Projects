#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    ElementType Element;
    Position Next;
};

List Read();        /* details omitted */
void Print(List L); /* details omitted */
List ReverseNewMemory(List L);
List Reverse(List L);

int main()
{
    List L1, L2;
    L1 = Read();
    Print(L1);
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */
List Read()
{
    Position dummy = (Position)malloc(sizeof(struct Node));
    dummy->Element = 0;
    dummy->Next = NULL;
    Position ptr = dummy;
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        int value;
        scanf("%d", &value);
        Position newNode = (Position)malloc(sizeof(struct Node));
        newNode->Element = value;
        ptr->Next = newNode;
        ptr = newNode;
        ptr->Next = NULL;
    }
    return dummy;
}

void Print(List L)
{
    L = L->Next;
    while (L->Next != NULL)
    {
        printf("%d ", L->Element);
        L = L->Next;
    }
    printf("%d\n", L->Element);
}

List ReverseNewMemory(List L)
{
    L = L->Next;
    if (L == NULL || L->Next == NULL)
    {
        Position dummy = (Position)malloc(sizeof(struct Node));
        dummy->Element = 0;
        dummy->Next = NULL;
        return dummy;
    }
    Position pre = (Position)malloc(sizeof(struct Node));
    pre->Next = NULL;
    pre->Element = L->Element;
    L = L->Next;
    while (L->Next != NULL)
    {
        Position newNode = (Position)malloc(sizeof(struct Node));
        newNode->Element = L->Element;
        newNode->Next = pre;
        pre = newNode;
        L = L->Next;
    }
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = L->Element;
    newNode->Next = pre;
    pre = newNode;
    Position dummy = (Position)malloc(sizeof(struct Node));
    dummy->Element = 0;
    dummy->Next = pre;
    L = dummy;
    return dummy;
}

List Reverse(List L)
{
    Position ptr = (Position)malloc(sizeof(struct Node));
    Position pre = (Position)malloc(sizeof(struct Node));
    ptr = L;
    L = L->Next;
    if (L == NULL || L->Next == NULL)
    {
        return ptr;
    }
    pre->Element = 0;
    ptr->Element = 0;
    pre->Next = L;
    L = L->Next;
    ptr->Next = L;
    pre->Next->Next = NULL;
    while (L->Next != NULL)
    {
        L = L->Next;
        ptr->Next->Next = pre->Next;
        pre->Next = ptr->Next;
        ptr->Next = L;
    }
    L->Next = pre->Next;
    ptr->Next = L;
    L = ptr;
    return L;
}
