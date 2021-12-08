/*
 * @Author: your name
 * @Date: 2021-12-04 03:18:37
 * @LastEditTime: 2021-12-08 18:03:33
 * @LastEditors: Please set LastEditors
 * @Description: StronglyConnectedComponents
 * @FilePath: \StronglyConnectedComponents\.dist\main.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10 /* maximum number of vertices */
typedef int Vertex;    /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode
{
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode
{
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV(Vertex V)
{
    printf("%d ", V);
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V));

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents(G, PrintV);
    return 0;
}

Graph ReadG()
{
    Graph G = (Graph)malloc(sizeof(struct GNode));
    int V, E;
    scanf("%d %d", &V, &E);
    G->NumOfVertices = V;
    G->NumOfEdges = E;
    G->Array = (PtrToVNode *)malloc(sizeof(PtrToVNode) * G->NumOfVertices);
    for (int i = 0; i < G->NumOfVertices; i++)
    {
        G->Array[i] = (PtrToVNode)malloc(sizeof(struct VNode));
        G->Array[i]->Vert = i;
        G->Array[i]->Next = NULL;
    }
    for (int i = 0; i < G->NumOfEdges; i++)
    {
        int S, D;
        scanf("%d %d", &S, &D);
        PtrToVNode New = (PtrToVNode)malloc(sizeof(struct VNode));
        New->Vert = D;
        New->Next = NULL;
        PtrToVNode Ptr = G->Array[S];
        while (Ptr->Next)
        {
            Ptr = Ptr->Next;
        }
        Ptr->Next = New;
    }
    printf("\n%d %d\n", G->NumOfVertices, G->NumOfEdges);
    for (int i = 0; i < G->NumOfVertices; i++)
    {
        PtrToVNode Ptr = G->Array[i];
        while (Ptr->Next)
        {
            printf("%d -> ", Ptr->Vert);
            Ptr = Ptr->Next;
        }
        printf("%d\n", Ptr->Vert);
    }
    return G;
}

/* Your function will be put here */

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V))
{
    int Connect[MaxVertices][MaxVertices] = {0};
    for (int i = 0; i < G->NumOfVertices; i++)
    {
        Connect[i][i] = 1;
        int index = 0;
        int Visited[MaxVertices] = {0};
        Visited[i] = 1;
        int Stack[MaxVertices] = {0};
        Stack[index++] = i;
        while (index >= 0)
        {
            int Pop = Stack[--index];
            PtrToVNode Ptr = G->Array[Pop];
            while (Ptr)
            {
                Connect[i][Ptr->Vert] = 1;
                if (Visited[Ptr->Vert] == 0)
                {
                    Visited[Ptr->Vert] = 1;
                    Stack[index++] = Ptr->Vert;
                }
                Ptr = Ptr->Next;
            }
        }
    }
    int Processed[MaxVertices] = {0};
    for (int i = 0; i < G->NumOfVertices; i++)
    {
        if (Processed[i] == 1)
        {
            continue;
        }
        int Path[MaxVertices] = {0};
        Path[i] = 1;
        for (int j = i; j < G->NumOfVertices; j++)
        {
            int Flag = 1;
            for (int tc_i = 0; tc_i < G->NumOfVertices; tc_i++)
            {
                if (Path[tc_i] == 1)
                {
                    if (!(Connect[j][tc_i] == 1 && Connect[tc_i][j] == 1))
                    {
                        Flag = 0;
                        break;
                    }
                }
            }
            if (Flag == 1)
            {
                Path[j] = 1;
            }
        }
        for (int ans_i = 0; ans_i < G->NumOfVertices; ans_i++)
        {
            if (Path[ans_i] == 1)
            {
                (*visit)(ans_i);
                Processed[ans_i] = 1;
            }
        }
        printf("\n");
    }
}
