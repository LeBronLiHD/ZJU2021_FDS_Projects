/*
 * @Author: your name
 * @Date: 2021-12-16 19:47:00
 * @LastEditTime: 2021-12-21 19:04:58
 * @LastEditors: Please set LastEditors
 * @Description: input graph, output the result and some debugging functions
 * @FilePath: \3_Project_Hard\input_output.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: read the graph as adjacency matrix
 * @param {int M, int N}
 * @return {int **G}
 */
int **read_graph(int M, int N)
{
    int **G = (int **)malloc(sizeof(int *) * M);    // allocate space
    for (int i = 0; i < M; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * M);      // allocate space
        for (int j = 0; j < M; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int start, dest, weight;
        scanf("%d %d %d", &start, &dest, &weight);  // read edges
        G[start - 1][dest - 1] = weight;            // store in matrix
        G[dest - 1][start - 1] = weight;            // unidirectional
    }
    return G;
}

/**
 * @description: show the graph, for debugging
 * @param {int **G, int M}
 * @return {*}
 */
void show_graph(int **G, int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
}

/**
 * @description: show the 2-nd shortest path, the result of project
 * @param {PATH *P}
 * @return {*}
 */
void show_path_length(PATH *P)
{
    printf("%d ", P->length);
    STEP *path = P->path;
    while (path->next)
    {
        printf("%d ", path->point + 1);
        path = path->next;
    }
    printf("%d\n", path->point + 1);
}

/**
 * @description: show the distance matrix after Dijkstra processing
 * @param {PATH **dist, int M}
 * @return {*}
 */
void show_dist(PATH **dist, int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d\t", dist[i][j].length);
        }
        printf("\n");
    }
}
