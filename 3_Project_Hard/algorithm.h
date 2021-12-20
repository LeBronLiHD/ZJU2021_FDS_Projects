/*
 * @Author: your name
 * @Date: 2021-12-16 23:32:19
 * @LastEditTime: 2021-12-21 01:48:26
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
        bool visited = FALSE;
        STEP *path = CP->path;
        STEP *path_ptr = NULL;
        while (path)
        {
            path_ptr = path;
            if (path->point == i)
            {
                visited = TRUE;
                break;
            }
            path = path->next;
        }
        if (visited == FALSE && G[point][i] != 0)
        {
            STEP *new_step = (STEP *)malloc(sizeof(struct Step));
            new_step->point = i;
            new_step->next = NULL;
            path_ptr->next = new_step;
            CP->length += G[point][i];
            if (CP->length >= R->second_min)
            {
                // pruning
                path_ptr->next = NULL;
                CP->length -= G[point][i];
                continue;
            }
            if (i == M - 1)
            {
                if (P->current->path == NULL)
                {
                    P->current->length = CP->length;
                    STEP *init_step = (STEP *)malloc(sizeof(struct Step));
                    STEP *ptr_step = CP->path;
                    init_step = NULL;
                    STEP *ptr_init_step = init_step;
                    while (ptr_step)
                    {
                        STEP *new_step_set = (STEP *)malloc(sizeof(struct Step));
                        new_step_set->point = ptr_step->point;
                        new_step_set->next = NULL;
                        if (ptr_init_step == NULL)
                        {
                            init_step = new_step_set;
                            ptr_init_step = init_step;
                        }
                        else
                        {
                            ptr_init_step->next = new_step_set;
                            ptr_init_step = new_step_set;
                        }
                        ptr_step = ptr_step->next;
                    }
                    P->current->path = init_step;
                }
                else
                {
                    PATHSET *ptr_pathset = P;
                    while (ptr_pathset->next)
                    {
                        ptr_pathset = ptr_pathset->next;
                    }
                    PATHSET *new_path = (PATHSET *)malloc(sizeof(struct PathSet));
                    new_path->current = (PATH *)malloc(sizeof(struct Path));
                    new_path->current->length = CP->length;
                    new_path->current->path = (STEP *)malloc(sizeof(struct Step));
                    STEP *ptr_step = CP->path;
                    new_path->current->path = NULL;
                    STEP *ptr_step_new = new_path->current->path;
                    while (ptr_step)
                    {
                        STEP *new_step_set = (STEP *)malloc(sizeof(struct Step));
                        new_step_set->point = ptr_step->point;
                        new_step_set->next = NULL;
                        if (ptr_step_new == NULL)
                        {
                            new_path->current->path = new_step_set;
                            ptr_step_new = new_path->current->path;
                        }
                        else
                        {
                            ptr_step_new->next = new_step_set;
                            ptr_step_new = new_step_set;
                        }
                        ptr_step = ptr_step->next;
                    }
                    new_path->next = NULL;
                    ptr_pathset->next = new_path;
                }
                if (CP->length < R->min)
                {
                    R->second_min = R->min;
                    R->min = CP->length;
                }
                else if (CP->length >= R->min && CP->length < R->second_min)
                {
                    R->second_min = CP->length;
                }
            }
            else
            {
                bool is_visited = FALSE;
                STEP *path = CP->path;
                while (path->next)
                {
                    if (path->point == i)
                    {
                        is_visited = TRUE;
                        break;
                    }
                    path = path->next;
                }
                if (is_visited == FALSE)
                {
                    dfs(G, i, M, CP, P, R);
                }
            }
            path_ptr->next = NULL;
            CP->length -= G[point][i];
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
    P->current = (PATH *)malloc(sizeof(struct Path));
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
    return P;
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
                new->next = (STEP *)malloc(sizeof(struct Step));
                new->next->point = i;
                new->next->next = NULL;
                STEP *ptr = S[i].path;
                ptr = NULL;
                STEP *copy_min = S[min_idx].path;
                while (copy_min->point != min_idx)
                {
                    STEP *new_min = (STEP *)malloc(sizeof(struct Step));
                    new_min->point = copy_min->point;
                    new_min->next = NULL;
                    copy_min = copy_min->next;
                    if (ptr == NULL)
                    {
                        S[i].path = new_min;
                        ptr = S[i].path;
                    }
                    else
                    {
                        ptr->next = new_min;
                        ptr = new_min;
                    }
                }
                if (ptr == NULL)
                {
                    S[i].path = new;
                }
                else
                {
                    ptr->next = new;
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
PATH **dijkstra(int **G, int M)
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
            dist[i][j].path = (STEP *)malloc(sizeof(struct Step));
            dist[i][j].path->point = i;
            dist[i][j].path->next = NULL;
        }
    }
    for (int i = 0; i < M; i++)
    {
        dij(G, M, dist[i], i);
    }
    show_dist(dist, M);
    return dist;
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
PATH *dijkstra_one_row(int **G, int M)
{
    PATH *dist = (PATH *)malloc(sizeof(PATH) * M);
    for (int i = 0; i < M; i++)
    {
        dist[i].length = INT_MAX;
        if (i == 0)
        {
            dist[i].length = 0;
        }
        dist[i].path = (STEP *)malloc(sizeof(struct Step));
        dist[i].path->point = i;
        dist[i].path->next = NULL;
    }
    dij(G, M, dist, 0);
    return dist;
}
