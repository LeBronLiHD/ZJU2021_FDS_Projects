/*
 * @Author: your name
 * @Date: 2021-11-24 11:12:24
 * @LastEditTime: 2021-11-24 20:01:43
 * @LastEditors: Please set LastEditors
 * @Description: IsTopologicalOrder
 * @FilePath: \IsTopologicalOrder\main.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;
#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 1 to MaxVertexNum */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

void Display(LGraph G);

bool IsTopSeq(LGraph Graph, Vertex Seq[]);

int main()
{
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    Display(G);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < G->Nv; j++)
            scanf("%d", &Seq[j]);
        if (IsTopSeq(G, Seq) == true)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

LGraph ReadG() /* details omitted */
{
    LGraph G = (LGraph)malloc(sizeof(struct GNode));
    int V, E;
    scanf("%d%d", &V, &E);
    G->Nv = V;
    G->Ne = E;
    for (int i = 0; i < E; i++)
    {
        G->G[i].FirstEdge = NULL;
    }
    for (int i = 0; i < E; i++)
    {
        int S, D;
        scanf("%d%d", &S, &D);
        PtrToAdjVNode P = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        P->AdjV = D;
        P->Next = G->G[S - 1].FirstEdge;
        G->G[S - 1].FirstEdge = P;

        PtrToAdjVNode P2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        P2->AdjV = S;
        P2->Next = G->G[D - 1].FirstEdge;
        G->G[D - 1].FirstEdge = P2;
    }
    return G;
}

void Display(LGraph G)
{
    printf("V -> %d\nE -> %d\n", G->Nv, G->Ne);
    for (int i = 0; i < G->Nv; i++)
    {
        PtrToAdjVNode P = G->G[i].FirstEdge;
        printf("Vertice %d -> ", i + 1);
        while (P != NULL)
        {
            printf("\t%d", P->AdjV);
            P = P->Next;
        }
        printf("\n");
    }
    return;
}

/* Your function will be put here */

int Degree[MaxVertexNum];

bool IsTopSeq(LGraph Graph, Vertex Seq[])
{
    for (int i = 0; i < Graph->Nv; i++)
    {
        Degree[Seq[i] - 1] = i;
    }
    for (int i = 0; i < Graph->Nv; i++)
    {
        PtrToAdjVNode Ptr = Graph->G[i].FirstEdge;
        while (Ptr != NULL)
        {
            if (Degree[i] > Degree[Ptr->AdjV])
            {
                return false;
            }
            Ptr = Ptr->Next;
        }
    }
    return true;
}
