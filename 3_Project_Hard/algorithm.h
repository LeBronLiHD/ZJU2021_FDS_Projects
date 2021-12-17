/*
 * @Author: your name
 * @Date: 2021-12-16 23:32:19
 * @LastEditTime: 2021-12-17 19:21:35
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
void dfs(int **G, int point, int M, PATH *CP, PATHSET *P, RECORD *R)
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
            if(CP->length >= R->second_min)
            {
                // pruning
                continue;
            }
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
                if (CP->length < R->min)
                {
                    R->second_min = R->min;
                    R->min = CP->length;
                }
                if (CP->length >= R->min && CP->length < R->second_min)
                {
                    R->second_min = CP->length;
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
                    bfs(G, i, M, CP, P, R);
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
PATHSET *basic_dfs(int **G, int M)
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
    RECORD *R = (RECORD *)malloc(sizeof(struct Record));
    R->min = INT_MAX;
    R->second_min = INT_MAX;
    R->second_exist = FALSE;
    dfs(G, 0, M, CP, P, R);
    R->second_exist = (R->second_min < INT_MAX);
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void dij(int **G, int M, PATH *S, int start)
{
    bool *visited = (bool *)malloc(sizeof(bool) * M);
    for (int i = 0; i < M; i++)
    {
        visited[i] = FALSE;
    }
    visited[start] = TRUE;
    int count = 0;
    while (count < M)
    {
        int min_idx = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < M; i++)
        {
            if (visited[i] == FALSE && S[i].length < min_len)
            {
                min_len = S[i].length;
                min_idx = i;
            }
        }
        visited[min_idx] = TRUE;
        count += 1;
        for (int i = 0; i < M; i++)
        {
            if (visited[i] == FALSE && G[min_idx][i] != 0 && (S[min_idx].length + G[min_idx][i]) < S[i].length)
            {
                S[i].length = S[min_idx].length + G[min_idx][i];
                STEP *new = (STEP *)malloc(sizeof(struct Step));
                new->point = min_idx;
                new->next = NULL;
                S[i].path->next = new;
            }
        }
    }
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
int **dijkstra(int **G, int M)
{
    PATH **dist = (PATH **)malloc(sizeof(PATH *) * M);
    for (int i = 0; i < M; i++)
    {
        dist[i] = (PATH *)malloc(sizeof(PATH) * M);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j].length = INT_MAX;
            if (i == j)
            {
                dist[i][j].length = 0;
            }
            if (G[i][j] != 0)
            {
                dist[i][j].length = G[i][j];
            }
            dist[i][j].path = (STEP *)malloc(sizeof(struct Step));
            dist[i][j].path->point = i;
            dist[i][j].path->next = NULL;
        }
    }
    for (int i = 0; i < M; i++)
    {
        dij(G, M, dist[i], i);
    }
    return dist;
}
