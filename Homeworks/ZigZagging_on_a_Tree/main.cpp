/*
 * @Author: your name
 * @Date: 2021-10-17 23:21:01
 * @LastEditTime: 2021-10-18 23:13:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ZigZagging_on_a_Tree\main.c
 */

#include <stdio.h>
#include <stdlib.h>

#define AAA 30

static const int N = 30;    // max number of total nodes
static int leftOrRight = 1; // direction of current row, left first
static int Number;          // number of total nodes

struct Order
{
    int Value;
    int Index;
    struct Order *Next;
};

static struct Order *OrderIn = NULL, *CurIn = NULL;
static struct Order *OrderPo = NULL, *CurPo = NULL;

struct Row
{
    int Value;
    struct Row *NextNode;
    struct Row *PreNode;
};

struct Levels
{
    struct Row *DummyHead;
    struct Row *DummyTail;
    int LoR; // direction, 1 -> left and 0 -> right
    int Depth;
};

static struct Levels *LEVEL[AAA];

void changeDirection()
{
    if (leftOrRight == 1)
        leftOrRight = 0;
    else
        leftOrRight = 1;
}

void showOrder()
{
    CurIn = OrderIn;
    while (CurIn)
    {
        printf("%d ", CurIn->Value);
        CurIn = CurIn->Next;
    }
    printf("\n");
    CurPo = OrderPo;
    while (CurPo)
    {
        printf("%d ", CurPo->Value);
        CurPo = CurPo->Next;
    }
    printf("\n");
}

void input()
{
    scanf("%d", &Number);
    for (int i = 0; i < Number; i++)
    {
        int unit;
        scanf("%d", &unit);
        if (i == 0)
        {
            OrderIn = (struct Order *)malloc(sizeof(struct Order));
            OrderIn->Value = unit;
            OrderIn->Index = i;
            OrderIn->Next = NULL;
            CurIn = OrderIn;
        }
        else
        {
            struct Order *NewIn = (struct Order *)malloc(sizeof(struct Order));
            NewIn->Value = unit;
            NewIn->Index = i;
            NewIn->Next = NULL;
            CurIn->Next = NewIn;
            CurIn = NewIn;
        }
    }
    for (int i = 0; i < Number; i++)
    {
        int unit;
        scanf("%d", &unit);
        if (i == 0)
        {
            OrderPo = (struct Order *)malloc(sizeof(struct Order));
            OrderPo->Value = unit;
            OrderPo->Index = i;
            OrderPo->Next = NULL;
            CurPo = OrderPo;
        }
        else
        {
            struct Order *NewPo = (struct Order *)malloc(sizeof(struct Order));
            NewPo->Value = unit;
            NewPo->Index = i;
            NewPo->Next = NULL;
            CurPo->Next = NewPo;
            CurPo = NewPo;
        }
    }
    showOrder(); // for debug
    for (int i = 0; i < N; i++)
    {
        LEVEL[i] = NULL;
    }
}

void display()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (LEVEL[i] == NULL)
        {
            break;
        }
        else
        {
            if (LEVEL[i]->LoR == 1)
            {
                struct Row *Cur = LEVEL[i]->DummyTail;
                while (Cur)
                {
                    if (count == Number - 1)
                    {
                        printf("%d", Cur->Value);
                    }
                    else
                    {
                        printf("%d ", Cur->Value);
                    }
                    count++;
                    Cur = Cur->PreNode;
                }
            }
            else
            {
                struct Row *Cur = LEVEL[i]->DummyHead;
                while (Cur)
                {
                    if (count == Number - 1)
                    {
                        printf("%d", Cur->Value);
                    }
                    else
                    {
                        printf("%d ", Cur->Value);
                    }
                    count++;
                    Cur = Cur->NextNode;
                }
            }
        }
    }
    return;
}

struct Order *LeftPart(struct Order *In, int separate)
{
    struct Order *InCopy = In;
    if (In->Value == separate)
    {
        return NULL;
    }
    int count = 0;
    struct Order *Left = (struct Order *)malloc(sizeof(struct Order));
    Left->Value = In->Value;
    Left->Next = NULL;
    Left->Index = count;
    count++;
    struct Order *CurLeft = Left;
    while (In->Next->Value != separate)
    {
        In = In->Next;
        struct Order *NewLeft = (struct Order *)malloc(sizeof(struct Order));
        NewLeft->Value = In->Value;
        NewLeft->Next = NULL;
        NewLeft->Index = count;
        count++;
        CurLeft->Next = NewLeft;
        CurLeft = NewLeft;
    }
    In = InCopy;
    return Left;
}

struct Order *RightPart(struct Order *In, int separate)
{
    struct Order *InCopy = In;
    while (In->Value != separate)
    {
        In = In->Next;
    }
    if (In->Next == NULL)
    {
        return NULL;
    }
    int count = 0;
    struct Order *Right = (struct Order *)malloc(sizeof(struct Order));
    Right->Index = count;
    count++;
    Right->Value = In->Next->Value;
    Right->Next = NULL;
    struct Order *CurRight = Right;
    In = In->Next;
    while (In->Next)
    {
        struct Order *NewRight = (struct Order *)malloc(sizeof(struct Order));
        NewRight->Index = count;
        count++;
        NewRight->Value = In->Next->Value;
        NewRight->Next = NULL;
        CurRight->Next = NewRight;
        CurRight = NewRight;
        In = In->Next;
    }
    In = InCopy;
    return Right;
}

void zigzag(int Depth, struct Order *In, struct Order *Po)
{
    // 1. separate
    // 2. recursion
    if (In == NULL && Po == NULL)
    {
        return;
    }
    CurPo = Po;
    if (CurPo == NULL)
    {
        printf("fuck!!! ");
    }
    struct Order *PoCopy = NULL, *CurPoCopy = NULL;
    int count = 0;
    while (CurPo->Next)
    {
        if (PoCopy == NULL)
        {
            PoCopy = (struct Order *)malloc(sizeof(struct Order));
            PoCopy->Index = count;
            count++;
            PoCopy->Value = CurPo->Value;
            PoCopy->Next = NULL;
            CurPoCopy = PoCopy;
        }
        else
        {
            struct Order *NewCopy = (struct Order *)malloc(sizeof(struct Order));
            NewCopy->Index = count;
            count++;
            NewCopy->Value = CurPo->Value;
            NewCopy->Next = NULL;
            CurPoCopy->Next = NewCopy;
            CurPoCopy = NewCopy;
        }
        CurPo = CurPo->Next;
    }
    int separate = CurPo->Value;
    if (LEVEL[Depth] == NULL)
    {
        LEVEL[Depth] = (struct Levels *)malloc(sizeof(struct Levels));
        LEVEL[Depth]->LoR = leftOrRight;
        changeDirection();
        LEVEL[Depth]->Depth = Depth;
        LEVEL[Depth]->DummyHead = (struct Row *)malloc(sizeof(struct Levels));
        LEVEL[Depth]->DummyHead->Value = separate;
        LEVEL[Depth]->DummyHead->NextNode = NULL;
        LEVEL[Depth]->DummyHead->PreNode = NULL;
        LEVEL[Depth]->DummyTail = LEVEL[Depth]->DummyHead;
    }
    else
    {
        struct Row *NewNode = (struct Row *)malloc(sizeof(struct Levels));
        NewNode->Value = separate;
        NewNode->NextNode = NULL;
        LEVEL[Depth]->DummyTail->NextNode = NewNode;
        NewNode->PreNode = LEVEL[Depth]->DummyTail;
        LEVEL[Depth]->DummyTail = NewNode;
    }

    struct Order *InLeft = LeftPart(In, separate);
    struct Order *InCount = InLeft;
    struct Order *PoCopyRight = NULL;
    if (InLeft == NULL)
    {
        PoCopyRight = PoCopy;
        PoCopy = NULL;
    }
    else
    {
        CurPoCopy = PoCopy;
        while (InCount->Next)
        {
            InCount = InCount->Next;
            CurPoCopy = CurPoCopy->Next;
        }
        PoCopyRight = CurPoCopy->Next;
        CurPoCopy->Next = NULL;
    }
    struct Order *InRight = RightPart(In, separate);

    zigzag(Depth + 1, InLeft, PoCopy);
    zigzag(Depth + 1, InRight, PoCopyRight);
}

int main()
{
    input();
    zigzag(0, OrderIn, OrderPo);
    display();
    return 0;
}
