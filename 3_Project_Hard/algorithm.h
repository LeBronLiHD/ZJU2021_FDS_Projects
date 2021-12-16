/*
 * @Author: your name
 * @Date: 2021-12-16 23:32:19
 * @LastEditTime: 2021-12-17 07:01:31
 * @LastEditors: Please set LastEditors
 * @Description: 3_Project_Hard
 * @FilePath: \3_Project_Hard\algorithm.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void bfs(int **G, int point, int M, PATH *CP, PATHSET *P)
{
    for (int i = 0; i < M; i++)
    {
        if (G[point][i] != 0)
        {
            STEP *new_step = (STEP *)malloc(sizeof(struct Step));
            new_step->point = i;
            new_step->next = NULL;
            CP->path->next = new_step;
            CP->length += G[point][i];
            if (i == M - 1)
            {
                if (P->current == NULL)
                {
                    P->current = CP;
                }
                else
                {
                    P->next = CP;
                }
            }
            else
            {
                bool visited = FALSE;
                STEP *path = CP->path;
                while (path)
                {
                    if (path->point == i)
                    {
                        visited = TRUE;
                        break;
                    }
                }
                if (visited == FALSE)
                {
                    bfs(G, i, M, CP, P);
                }
            }
        }
    }
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
PATHSET *basic_bfs(int **G, int M)
{
    PATHSET *P = (PATHSET *)malloc(sizeof(struct PathSet));
    P->current->length = 0;
    P->current->path = NULL;
    P->next = NULL;
    PATH *CP = (PATH *)malloc(sizeof(struct Path));
    CP->length = 0;
    CP->path = (STEP *)malloc(sizeof(struct Step));
    CP->path->point = 0;
    CP->path->next = NULL;
    bfs(G, 0, M, CP, P);
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void dij(int **G, int M, int *S)
{
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
int **dijkstra(int **G, int M)
{
    int **dist = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
        dist[i] = (int *)malloc(sizeof(int) * M);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j] = INT_MAX;
            if (i == j)
            {
                dist[i][j] = 0;
            }
            if (G[i][j] != 0)
            {
                dist[i][j] = G[i][j];
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        dij(G, M, dist[i]);
    }
    return dist;
}
