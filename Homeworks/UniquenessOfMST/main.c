/*
 * @Author: your name
 * @Date: 2021-12-04 02:41:36
 * @LastEditTime: 2021-12-07 23:43:59
 * @LastEditors: Please set LastEditors
 * @Description: UniquenessOfMST
 * @FilePath: \UniquenessOfMST\main.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 501
int FATHER[MAX_SIZE];
int V, E;
typedef enum bool
{
    FALSE,
    TRUE
} bool;
typedef struct EDGE
{
    int Start;
    int Dest;
    int Weight;
    bool Visited;
} EDGE;
EDGE EDGES[MAX_SIZE];
EDGE EDGES_SORTED[MAX_SIZE];
int NUM, SUM;
bool FLAG = TRUE;

void show_ori_edges()
{
    for (int i = 0; i < E; i++)
    {
        printf("%d -> %d = %d\n", EDGES[i].Dest,
               EDGES[i].Dest, EDGES[i].Weight);
    }
}

void show_edges()
{
    printf("\n");
    show_ori_edges();
    printf("\n");
    for (int i = 0; i < E; i++)
    {
        printf("%d -> %d = %d\n", EDGES_SORTED[i].Dest,
               EDGES_SORTED[i].Dest, EDGES_SORTED[i].Weight);
    }
}

void sort_edges()
{
    for (int i = 0; i < E; i++)
    {
        int min_index = 0;
        int min_weight = INT_MAX;
        for (int j = 0; j < E; j++)
        {
            if (EDGES[j].Visited == FALSE && 0 < EDGES[j].Weight && EDGES[j].Weight < min_weight)
            {
                min_weight = EDGES[j].Weight;
                min_index = j;
            }
        }
        EDGES_SORTED[i].Dest = EDGES[min_index].Dest;
        EDGES_SORTED[i].Start = EDGES[min_index].Start;
        EDGES_SORTED[i].Weight = EDGES[min_index].Weight;
        EDGES[min_index].Visited = TRUE;
    }
}

void init_graph()
{
    scanf("%d %d", &V, &E);
    int index = 0;
    for (int i = 0; i < E; i++)
    {
        int V1, V2, Weight;
        scanf("%d %d %d", &V1, &V2, &Weight);
        EDGES[index].Start = V1;
        EDGES[index].Dest = V2;
        EDGES[index].Weight = Weight;
        EDGES[index++].Visited = FALSE;
    }
}

int is_circle(int Vx)
{
    if (Vx == FATHER[Vx])
    {
        return Vx;
    }
    int F = is_circle(FATHER[Vx]);
    FATHER[Vx] = F;
    return F;
}

void number_of_MST()
{
    int j = 0;
    for (int i = 0; i < E; i++)
    {
        FATHER[i] = i;
    }
    for (int i = 0; i < E; i = j)
    {
        for (j = i; j < E && EDGES_SORTED[j].Weight == EDGES_SORTED[i].Weight; j++)
        {
            if (is_circle(EDGES_SORTED[j].Start) != is_circle(EDGES_SORTED[j].Dest))
            {
                EDGES_SORTED[j].Visited = TRUE;
            }
        }
        for (int k = i; k < j; k++)
        {
            int Fa = is_circle(EDGES_SORTED[k].Start);
            int Fb = is_circle(EDGES_SORTED[k].Dest);
            if (Fa != Fb)
            {
                SUM += EDGES_SORTED[k].Weight;
                FATHER[Fa] = Fb;
                NUM++;
            }
            else if (EDGES_SORTED[k].Visited)
            {
                FLAG = FALSE;
            }
        }
    }
}

void show_result()
{
    if (NUM == V - 1)
    {
        printf("%d\n", SUM);
        if (FLAG == TRUE)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
    }
    else
    {
        printf("No MST\n%d", V - NUM);
    }
}

int main()
{
    printf("%d\n", INT_MAX);
    init_graph();
    sort_edges();
    show_edges();
    number_of_MST();
    show_result();
    return 0;
}
