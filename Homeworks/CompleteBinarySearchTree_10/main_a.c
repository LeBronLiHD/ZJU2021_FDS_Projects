/*
 * @Author: your name
 * @Date: 2021-10-29 10:39:51
 * @LastEditTime: 2021-10-29 14:59:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CompleteBinarySearchTree\main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXDEPTH 15
#define TRUE 1
#define DEBUG 0
#define SEVEN 0
#define TEN 1
int SIZE = 0;
int CBT[1010];
int BUILDIDX = 0;

struct Levels
{
    int value;
    struct Levels *next;
    struct Levels *tail;
};

struct Levels *LEVEL[MAXDEPTH];

struct Input
{
    int value;
    struct Input *next;
};

void DisplayLevels()
{
    int count = 0;
    for (int i = 0; i < MAXDEPTH; i++)
    {
        if (LEVEL[i] == NULL)
            break;
        else
        {
            struct Levels *L = LEVEL[i];
            while (L)
            {
                printf("%d", L->value);
                count++;
                if (count < SIZE)
                    printf(" ");
                L = L->next;
            }
        }
    }
    return;
}

int CalculateNodes(int depth)
{
    return pow(2, depth) - 1;
}

int RootIndex(int size)
{
    if (size == 1 || size == 2)
        return size;
    int D = 0;
    for (int i = 1; i < size + 1; i++)
    {
        if (CalculateNodes(i) > size)
        {
            D = i;
            break;
        }
    }
    int NumOfLeaves = size - CalculateNodes(D - 1);
    int LeftLeaves = (NumOfLeaves > pow(2, D - 2)) ? pow(2, D - 2) : NumOfLeaves;
    // int RightLeaves = NumOfLeaves - LeftLeaves;
    if (NumOfLeaves == 0)
        return (size + 1) / 2;
    else
        return LeftLeaves + (size + 1 - NumOfLeaves) / 2;
}

void BuildLevels(int Depth, int size, struct Input *CurIn)
{
    if(size < 0)
        printf("fuck");
    if (CurIn == NULL)
        return;
    int index = RootIndex(size);
    struct Input *Left, *Right = NULL, *toDel = NULL;
    Left = CurIn;
    for (int i = 1; i < index; i++)
    {
        toDel = CurIn;
        CurIn = CurIn->next;
    }
    int root = CurIn->value;
    if (size == 1)
    {
        Left = NULL;
        Right = NULL;
    }
    else
    {
        Right = CurIn->next;
        if (toDel == NULL)
            Left->next = NULL;
        else
            toDel->next = NULL;
        free(CurIn);
    }
    if (LEVEL[Depth] == NULL)
    {
        LEVEL[Depth] = (struct Levels *)malloc(sizeof(struct Levels));
        LEVEL[Depth]->value = root;
        LEVEL[Depth]->next = NULL;
        LEVEL[Depth]->tail = LEVEL[Depth];
    }
    else
    {
        struct Levels *New = (struct Levels *)malloc(sizeof(struct Levels));
        New->value = root;
        New->next = NULL;
        New->tail = NULL;
        LEVEL[Depth]->tail->next = New;
        LEVEL[Depth]->tail = New;
    }
    BuildLevels(Depth + 1, index - 1, Left);
    BuildLevels(Depth + 1, size - index, Right);
}

void DisplayInput(struct Input *IN)
{
    while (IN)
    {
        printf("%d ", IN->value);
        IN = IN->next;
    }
    printf("\n");
}

void Insert(struct Input *IN, int unit)
{
    struct Input *Cur = IN;
    struct Input *New = (struct Input *)malloc(sizeof(struct Input));
    New->value = unit;
    New->next = NULL;
    while (TRUE)
    {
        if (Cur->value > unit)
            break;
        if (Cur->next)
            Cur = Cur->next;
        else
            break;
    }
    if (Cur->next == NULL && Cur->value < unit)
        Cur->next = New;
    else if (Cur == IN)
    {
        New->next = Cur->next;
        Cur->next = New;
        int tmp = New->value;
        New->value = Cur->value;
        Cur->value = tmp;
    }
    else
    {
        New->next = Cur->next;
        Cur->next = New;
    }
}

int IndexValue(int index, struct Input *IN)
{
    for (int i = 0; i < index; i++)
    {
        IN = IN->next;
    }
    return IN->value;
}

void BuildCBT(int root, struct Input *IN)
{
    if(root > SIZE)
        return;
    BuildCBT(root * 2, IN);
    CBT[root] = IndexValue(BUILDIDX++, IN);
    BuildCBT(root * 2 + 1, IN);
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    SIZE = N;
    struct Input *IN = NULL;
    for (int i = 0; i < N; i++)
    {
        int unit = 0;
        scanf("%d", &unit);
        if (IN == NULL)
        {
            IN = (struct Input *)malloc(sizeof(struct Input));
            IN->value = unit;
            IN->next = NULL;
        }
        else
        {
            Insert(IN, unit);
        }
    }
    if (DEBUG)
        DisplayInput(IN);
    if (SEVEN)
    {
        BuildLevels(0, N, IN);
        DisplayLevels();
    }
    if (TEN)
    {
        // printf("fuck");
        BuildCBT(1, IN);
        for (int i = 1; i <= N - 1; i++)
        {
            printf("%d ", CBT[i]);
        }
        printf("%d", CBT[N]);
    }
}
