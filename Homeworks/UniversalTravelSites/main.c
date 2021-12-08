/*
 * @Author: your name
 * @Date: 2021-12-04 00:38:33
 * @LastEditTime: 2021-12-06 01:19:08
 * @LastEditors: Please set LastEditors
 * @Description: Universal Travel Sites
 * @FilePath: \UniversalTravelSites\main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 501 // ac: 5001 hahaha...
#define DEBUG_MODE 0

enum bool
{
    FALSE,
    TRUE
};
typedef enum bool bool;

int MAT[MAX_SIZE][MAX_SIZE];
int N = 0;
int CurrentMark = 0;
struct Label
{
    char Name[4];
    int Mark;
    struct Label *Next;
};
typedef struct Label *PtrLabel;
PtrLabel MAP;

void DisplayMAP()
{
    PtrLabel Cur = MAP;
    while (Cur)
    {
        printf("%s\t%d\n", Cur->Name, Cur->Mark);
        Cur = Cur->Next;
    }
}

void InitStartAndDest()
{
    char *S, *D;
    S = (char *)malloc(sizeof(char) * 4);
    D = (char *)malloc(sizeof(char) * 4);
    scanf("\n%s %s", S, D);
    scanf("%d", &N);
    MAP = (PtrLabel)malloc(sizeof(struct Label));
    MAP->Next = NULL;
    // MAP->Name = S;
    strcpy(MAP->Name, S);
    MAP->Mark = CurrentMark++;
    PtrLabel New = (PtrLabel)malloc(sizeof(struct Label));
    New->Next = NULL;
    // New->Name = D;
    strcpy(New->Name, D);
    New->Mark = CurrentMark++;
    MAP->Next = New;
}

int GetIndex(char *S)
{
    PtrLabel Cur = MAP;
    while (Cur->Next)
    {
        if (strcmp(Cur->Name, S) == 0)
        {
            return Cur->Mark;
        }
        Cur = Cur->Next;
    }
    if (strcmp(Cur->Name, S) == 0)
    {
        return Cur->Mark;
    }
    else
    {
        PtrLabel New = (PtrLabel)malloc(sizeof(struct Label));
        New->Next = NULL;
        strcpy(New->Name, S);
        New->Mark = CurrentMark++;
        Cur->Next = New;
        return New->Mark;
    }
}

void ShowMAT()
{
    for (int i = 0; i < CurrentMark; i++)
    {
        for (int j = 0; j < CurrentMark; j++)
        {
            printf("%d\t", MAT[i][j]);
        }
        printf("\n");
    }
}

void ConstructGraph()
{
    for (int i = 0; i < N; i++)
    {
        char *S, *D;
        int C;
        S = (char *)malloc(sizeof(char) * 4);
        D = (char *)malloc(sizeof(char) * 4);
        scanf("%s %s", S, D);
        scanf("%d", &C);
        if (DEBUG_MODE)
        {
            printf("%d(%s) , %d(%s) -> %d\n", GetIndex(S), S, GetIndex(D), D, C);
        }
        if (MAT[GetIndex(D)][GetIndex(S)] != 0)
        {
            if (MAT[GetIndex(D)][GetIndex(S)] > C)
            {
                MAT[GetIndex(D)][GetIndex(S)] -= C;
            }
            else
            {
                MAT[GetIndex(S)][GetIndex(D)] = C - MAT[GetIndex(D)][GetIndex(S)];
            }
        }
        else
        {
            MAT[GetIndex(S)][GetIndex(D)] = C;
        }
    }
    if (DEBUG_MODE)
    {
        ShowMAT();
    }
}

bool BFS(int Source, int Dest, int Parent[])
{
    bool Visit[MAX_SIZE];
    int Queue[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Visit[i] = FALSE;
        Queue[i] = -1;
    }
    Visit[Source] = TRUE;
    int Index = 0;
    Queue[Index] = Source;
    while (Queue[Index] >= 0)
    {
        int U = Queue[Index++];
        int Delta = 0;
        for (int i = 0; i < CurrentMark; i++)
        {
            if (Visit[i] == FALSE && MAT[U][i] > 0)
            {
                Queue[Index + Delta] = i;
                Delta++;
                Visit[i] = TRUE;
                Parent[i] = U;
            }
        }
    }
    return Visit[Dest];
}

int GetMaxFlow(int Source, int Dest)
{
    // Ford-Fulkerson Algorithm
    int M = 0, P = 0;
    int Parent[MAX_SIZE];
    for (int i = 0; i < CurrentMark; i++)
    {
        Parent[i] = -1;
    }
    while (BFS(Source, Dest, Parent) == TRUE)
    {
        P = INT_MAX; // 2147483648 - 1
        int S = Dest;
        while (S != Source)
        {
            P = (P > MAT[Parent[S]][S]) ? MAT[Parent[S]][S] : P;
            S = Parent[S];
        }
        M += P;
        int V = Dest, U;
        while (V != Source)
        {
            U = Parent[V];
            MAT[U][V] -= P;
            MAT[V][U] += P;
            V = Parent[V];
        }
    }
    return M;
}

int main()
{
    InitStartAndDest();
    ConstructGraph();
    printf("%d", GetMaxFlow(0, 1));
    return 0;
}
