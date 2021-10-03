#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
/*
C: sizeof(struct Node);
C++: sizeof(Node);
*/
struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read();        /* details omitted */
void Print(Polynomial p); /* details omitted */
Polynomial Add(Polynomial a, Polynomial b);

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(a);
    Print(b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Read()
{
    Polynomial dummy = (Polynomial)malloc(sizeof(Node));
    dummy->Coefficient = 0;
    dummy->Exponent = 0;
    dummy->Next = NULL;
    Polynomial ptr = dummy;
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        int curCoe, curExp;
        scanf("%d", &curCoe);
        scanf("%d", &curExp);
        Polynomial newNode = (Polynomial)malloc(sizeof(Node));
        newNode->Coefficient = curCoe;
        newNode->Exponent = curExp;
        ptr->Next = newNode;
        ptr = newNode;
        ptr->Next = NULL;
    }
    return dummy;
}

void Print(Polynomial p)
{
    while (p->Next->Next != NULL)
    {
        p = p->Next;
        printf("%d %d ", p->Coefficient, p->Exponent);
    }
    p = p->Next;
    printf("%d %d\n", p->Coefficient, p->Exponent);
}

Polynomial Add(Polynomial a, Polynomial b)
{
    Polynomial dummy = (Polynomial)malloc(sizeof(Node));
    dummy->Coefficient = 0;
    dummy->Exponent = 0;
    dummy->Next = NULL;
    Polynomial ptr = dummy;
    while (a->Next != NULL && b->Next != NULL)
    {
        if (a->Next->Exponent > b->Next->Exponent)
        {
            a = a->Next;
            Polynomial newNode = (Polynomial)malloc(sizeof(Node));
            newNode->Coefficient = a->Coefficient;
            newNode->Exponent = a->Exponent;
            ptr->Next = newNode;
            ptr = newNode;
            ptr->Next = NULL;
        }
        else if (a->Next->Exponent < b->Next->Exponent)
        {
            b = b->Next;
            Polynomial newNode = (Polynomial)malloc(sizeof(Node));
            newNode->Coefficient = b->Coefficient;
            newNode->Exponent = b->Exponent;
            ptr->Next = newNode;
            ptr = newNode;
            ptr->Next = NULL;
        }
        else
        {
            a = a->Next;
            b = b->Next;
            if (a->Coefficient + b->Coefficient == 0)
            {
                continue;
            }
            else
            {
                Polynomial newNode = (Polynomial)malloc(sizeof(Node));
                newNode->Coefficient = b->Coefficient + a->Coefficient;
                newNode->Exponent = b->Exponent;
                ptr->Next = newNode;
                ptr = newNode;
                ptr->Next = NULL;
            }
        }
    }
    while (a->Next != NULL)
    {
        a = a->Next;
        Polynomial newNode = (Polynomial)malloc(sizeof(Node));
        newNode->Coefficient = a->Coefficient;
        newNode->Exponent = a->Exponent;
        ptr->Next = newNode;
        ptr = newNode;
        ptr->Next = NULL;
    }
    while (b->Next != NULL)
    {
        b = b->Next;
        Polynomial newNode = (Polynomial)malloc(sizeof(Node));
        newNode->Coefficient = b->Coefficient;
        newNode->Exponent = b->Exponent;
        ptr->Next = newNode;
        ptr = newNode;
        ptr->Next = NULL;
    }
    return dummy;
}
