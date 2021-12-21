/*
 * @Author: your name
 * @Date: 2021-12-16 23:32:19
 * @LastEditTime: 2021-12-21 20:25:54
 * @LastEditors: Please set LastEditors
 * @Description: algorithms of the project, DFS, Dijkstra...
 * @FilePath: \3_Project_Hard\algorithm.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: Depth First Search for all valid paths from 1 to M
 * @param {int **G, int point, int M, PATH *CP, PATHSET *P, RECORD *R}
 * @return {*}
 */
void dfs(int **G, int point, int M, PATH *CP, PATHSET *P, RECORD *R)
{
    for (int i = 0; i < M; i++)
    {
        bool visited = FALSE;
        STEP *path = CP->path;
        STEP *path_ptr = NULL;
        while (path) // check if the node haven't been visited
        {
            path_ptr = path;
            if (path->point == i)
            {
                visited = TRUE; // if the node is already in the path
                break;
            }
            path = path->next;
        }
        if (visited == FALSE && G[point][i] != 0)
        {
            // if the node haven't been visited and there exist an edge
            STEP *new_step = (STEP *)malloc(sizeof(struct Step));
            new_step->point = i; // creat a new STEP
            new_step->next = NULL;
            path_ptr->next = new_step;
            CP->length += G[point][i]; // update the length
            if (CP->length >= R->second_min)
            {
                path_ptr->next = NULL;
                CP->length -= G[point][i];
                continue; // if the length is already longer than the 2-nd shortest, pruning
            }
            if (i == M - 1)
            {
                // if we have reached the final node, document the current path to the path set
                if (P->current->path == NULL)
                {
                    // if the path set is empty, just let the current path be the first path
                    P->current->length = CP->length;                       // assign the length
                    STEP *init_step = (STEP *)malloc(sizeof(struct Step)); // allocate space
                    STEP *ptr_step = CP->path;                             // point to the current path
                    init_step = NULL;
                    STEP *ptr_init_step = init_step;
                    while (ptr_step)
                    {
                        STEP *new_step_set = (STEP *)malloc(sizeof(struct Step));
                        new_step_set->point = ptr_step->point; // copy the node
                        new_step_set->next = NULL;
                        if (ptr_init_step == NULL)
                        {
                            init_step = new_step_set;
                            ptr_init_step = init_step;
                        }
                        else
                        {
                            ptr_init_step->next = new_step_set; // push the new node to path
                            ptr_init_step = new_step_set;       // point to the last node
                        }
                        ptr_step = ptr_step->next;
                    }
                    P->current->path = init_step;
                }
                else
                {
                    // if the path set is not empty, link the current path to the tail of the path set
                    PATHSET *ptr_pathset = P;
                    while (ptr_pathset->next)
                    {
                        ptr_pathset = ptr_pathset->next;
                    }
                    // locate the end position of the path set
                    PATHSET *new_path = (PATHSET *)malloc(sizeof(struct PathSet)); // allocate space for new path
                    new_path->current = (PATH *)malloc(sizeof(struct Path));
                    new_path->current->length = CP->length;                        // assign the length
                    new_path->current->path = (STEP *)malloc(sizeof(struct Step)); // allocate space for new step
                    STEP *ptr_step = CP->path;
                    new_path->current->path = NULL;
                    STEP *ptr_step_new = new_path->current->path;
                    while (ptr_step)
                    {
                        STEP *new_step_set = (STEP *)malloc(sizeof(struct Step)); // allocate space for new step
                        new_step_set->point = ptr_step->point;                    // copy the node
                        new_step_set->next = NULL;
                        if (ptr_step_new == NULL)
                        {
                            new_path->current->path = new_step_set;
                            ptr_step_new = new_path->current->path;
                        }
                        else
                        {
                            ptr_step_new->next = new_step_set; // push the new node to path
                            ptr_step_new = new_step_set;       // point to the last node
                        }
                        ptr_step = ptr_step->next;
                    }
                    new_path->next = NULL;
                    ptr_pathset->next = new_path;
                }
                if (CP->length < R->min)
                {
                    R->second_min = R->min; // update the values in RECORD R
                    R->min = CP->length;
                }
                else if (CP->length >= R->min && CP->length < R->second_min)
                {
                    R->second_min = CP->length;
                }
            }
            else
            {
                // if we haven't reached the final node yet, just push to deeper layer
                bool is_visited = FALSE;
                STEP *path = CP->path;
                while (path->next)
                {
                    if (path->point == i)
                    {
                        is_visited = TRUE; // ensure the current haven't been visited
                        break;
                    }
                    path = path->next;
                }
                if (is_visited == FALSE)
                {
                    dfs(G, i, M, CP, P, R); // push to deeper layer
                }
            }
            path_ptr->next = NULL;     // back to origin after popping
            CP->length -= G[point][i]; // update the length
        }
    }
}

/**
 * @description: Depth First Search for all valid paths from 1 to M
 * @param {int **G, int M}
 * @return {PATHSET *P}
 */
PATHSET *basic_dfs(int **G, int M)
{
    PATHSET *P = (PATHSET *)malloc(sizeof(struct PathSet)); // allocate space for path set
    P->current = (PATH *)malloc(sizeof(struct Path));
    P->current->length = 0;
    P->current->path = NULL;
    P->next = NULL;
    PATH *CP = (PATH *)malloc(sizeof(struct Path)); // allocate space for current path
    CP->length = 0;
    CP->path = (STEP *)malloc(sizeof(struct Step));
    CP->path->point = 0;
    CP->path->next = NULL;
    RECORD *R = (RECORD *)malloc(sizeof(struct Record)); // allocate space for record
    R->min = INT_MAX;
    R->second_min = INT_MAX;
    R->second_exist = FALSE;
    dfs(G, 0, M, CP, P, R); // call the DFS function
    R->second_exist = (R->second_min < INT_MAX);
    return P;
}

/**
 * @description: use Dijkstra to fund the shortest path from the start point to all other nodes
 * @param {int **G, int M, PATH *S, int start}
 * @return {*}
 */
void dij(int **G, int M, PATH *S, int start)
{
    bool *visited = (bool *)malloc(sizeof(bool) * M);
    for (int i = 0; i < M; i++)
    {
        visited[i] = FALSE; // document whether the node has been visited
    }
    int count = 0;
    while (count < M)
    {
        int min_idx = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < M; i++)
        {
            // find the shortest path of all nodes, and mark it "visited"
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
                // if any unvisited nodes has shorter paths, update
                S[i].length = S[min_idx].length + G[min_idx][i];
                STEP *new = (STEP *)malloc(sizeof(struct Step)); // allocate space for new node
                new->point = min_idx;                            // assign the current with min_idx
                new->next = (STEP *)malloc(sizeof(struct Step)); // allocate space for new node
                new->next->point = i;                            // assign the next with i
                new->next->next = NULL;
                STEP *ptr = S[i].path;
                ptr = NULL;
                STEP *copy_min = S[min_idx].path;
                while (copy_min->point != min_idx)
                {
                    // first we copy the path from 0 to min_idx
                    // then add the new step to the end of road
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
 * @description: Dijkstra for every node in the graph
 * @param {int **G, int M}
 * @return {PATH **dist}
 */
PATH **dijkstra(int **G, int M)
{
    PATH **dist = (PATH **)malloc(sizeof(PATH *) * M); // allocate space for dist
    for (int i = 0; i < M; i++)
    {
        dist[i] = (PATH *)malloc(sizeof(struct Path) * M); // allocate space for dist[i]
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j].length = INT_MAX; // assign with INT_MAX as init value
            if (i == j)
            {
                dist[i][j].length = 0;
            }
            dist[i][j].path = (STEP *)malloc(sizeof(struct Step)); // allocate space for paths
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

/**
 * @description: only use Dijkstra for node 0
 * @param {int **G, int M}
 * @return {PATH *dist}
 */
PATH *dijkstra_one_row(int **G, int M)
{
    PATH *dist = (PATH *)malloc(sizeof(struct Path) * M); // allocate space for dist
    for (int i = 0; i < M; i++)
    {
        dist[i].length = INT_MAX; // assign with INT_MAX as init value
        if (i == 0)
        {
            dist[i].length = 0;
        }
        dist[i].path = (STEP *)malloc(sizeof(struct Step)); // allocate space for paths
        dist[i].path->point = i;
        dist[i].path->next = NULL;
    }
    dij(G, M, dist, 0);
    return dist;
}

/**
 * @description: cut the edge from the shortset path, and find the shortest path of new graph
 * @param {PATH *D, int **G, int M}
 * @return {*}
 */
void dijkstra_cut(PATH *D, int **G, int M)
{
    STEP *P = D[M - 1].path;
    STEP *ptr_p = P;
    int count = 0;
    while (ptr_p->next) // first we count the number of edges from the path
    {
        ptr_p = ptr_p->next;
        count += 1;
    }
    ptr_p = P;
    PATH *S = (PATH *)malloc(sizeof(struct Path)); // allocate space for S
    S->length = INT_MAX;                           // S is the second shortest path we will find
    S->path = (STEP *)malloc(sizeof(struct Step)); // allocate for path
    S->path = NULL;
    for (int i = 0; i < count; i++)
    {
        int start = ptr_p->point;
        int dest = ptr_p->next->point;
        int weight = G[start][dest];
        G[start][dest] = 0;                                // cut the edge
        PATH *N = (PATH *)malloc(sizeof(struct Path) * M); // allocate space
        for (int j = 0; j < M; j++)
        {
            N[j].length = INT_MAX;
            if (j == 0)
            {
                N[j].length = 0;
            }
            N[j].path = (STEP *)malloc(sizeof(struct Step));
            N[j].path->point = 0;
            N[j].path->next = NULL;
        }
        dij(G, M, N, 0); // use Dijkstra to find the shortest paths of the new graph
        if (S->length >= N[M - 1].length && N[M - 1].length < INT_MAX)
        {
            // if we got shorter path, update
            S->length = N[M - 1].length;
            S->path = NULL;
            STEP *ptr_s = S->path, *ptr_n = N[M - 1].path;
            while (ptr_n)
            {
                // allocate space and copy the path calculated using Dijkstra
                STEP *new_s = (STEP *)malloc(sizeof(struct Step));
                new_s->point = ptr_n->point;
                new_s->next = NULL;
                if (ptr_s == NULL)
                {
                    S->path = new_s;
                    ptr_s = S->path;
                }
                else
                {
                    ptr_s->next = new_s;
                    ptr_s = new_s;
                }
                ptr_n = ptr_n->next;
            }
        }
        G[start][dest] = weight; // repair the graph
        ptr_p = ptr_p->next;
    }
    printf("cut -> ");
    if (S->length < INT_MAX) // check if we have two or more paths
    {
        show_path_length(S);
    }
    else
    {
        printf("Less than 2 Paths!!!!!\n");
    }
}
