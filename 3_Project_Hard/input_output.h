/*
 * @Author: your name
 * @Date: 2021-12-16 19:47:00
 * @LastEditTime: 2021-12-17 06:00:05
 * @LastEditors: Please set LastEditors
 * @Description: input graph and output the result
 * @FilePath: \3_Project_Hard\input_output.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: read the graph as matrix
 * @param {*}
 * @return {*}
 */
int **read_graph(int M, int N)
{
    int **G = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * M);
        for (int j = 0; j < M; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int start, dest, weight;
        scanf("%d %d %d", &start, &dest, &weight);
        G[start - 1][dest - 1] = weight;
        G[dest - 1][start - 1] = weight;
    }
    return G;
}

/**
 * @description: show the graph, for debugging
 * @param {*}
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
 * @description: show the graph, for debugging
 * @param {*}
 * @return {*}
 */
void show_path_length(PATH *P)
{
    printf("%d ", P->length);
    STEP *path = P->path;
    while (path->next)
    {
        printf("%d ", path->point);
        path = path->next;
    }
    printf("%d", path->point);
}
