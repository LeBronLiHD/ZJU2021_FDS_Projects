/*
 * @Author: your name
 * @Date: 2021-11-24 19:47:48
 * @LastEditTime: 2021-11-24 21:06:52
 * @LastEditors: Please set LastEditors
 * @Description: Hamiltonian Cycle
 * @FilePath: \HamiltonianCycle\main.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;
#define MaxVertexNum 201 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 1 to MaxVertexNum */

int CountFlag();

bool DEBUG_MODE = false;

int FLAG[MaxVertexNum];

int main()
{
    int i, j, count;
    int V, E;
    int NE, NV;
    int MAT[MaxVertexNum][MaxVertexNum] = {0};
    int C[MaxVertexNum];
    scanf("%d%d", &V, &E);
    NV = V;
    NE = E;
    for (int i = 0; i < E; i++)
    {
        int S, D;
        scanf("%d%d", &S, &D);

        MAT[S - 1][D - 1] = 1;
        MAT[D - 1][S - 1] = 1;
    }
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        int N;
        scanf("%d", &N);
        for (int k = 0; k < MaxVertexNum; k++)
        {
            FLAG[k] = 0;
            C[k] = 0;
        }
        for (int k = 0; k < N; k++)
        {
            int unit;
            scanf("%d", &unit);
            C[k] = unit;
            FLAG[C[k] - 1]++;
        }
        bool F1 = true, F2 = true;
        if (CountFlag() != NV || N != NV + 1 || C[0] != C[N - 1])
        {
            F1 = false;
            printf("NO\n");
            continue;
        }
        for (int k = 0; k < N - 1; k++)
        {
            if (MAT[C[k] - 1][C[k + 1] - 1] == 0)
            {
                F2 = false;
                break;
            }
        }
        printf("%s", F2 ? "YES\n" : "NO\n");
    }
    return 0;
}

int CountFlag()
{
    int count = 0;
    for (int i = 0; i < MaxVertexNum; i++)
    {
        if (FLAG[i] != 0)
        {
            count++;
        }
    }
    return count;
}
