/*
 * @Author: your name
 * @Date: 2021-12-16 17:03:05
 * @LastEditTime: 2021-12-21 22:29:08
 * @LastEditors: Please set LastEditors
 * @Description: main file of 3_Project_Hard
 * @FilePath: \3_Project_Hard\main.c
 */

#include "input_output.h"
#include "data_structure.h"
#include "algorithm.h"
#include "basic_operation.h"
#include "clock.h"

int M, N;
int **G;

/**
 * @description: main Function of the Project
 * @param {*}
 * @return {*}
 */
int main()
{
    scanf("%d %d", &M, &N);
    G = read_graph(M, N);                       // construct the unidirectional graph
    program_start();                            // set up the timer
    search_second(basic_dfs(G, M), 0);          // Depth First Search (DFS) & Pruning
    algorithm_one();                            // calculate the time spent
    dijkstra_second(dijkstra(G, M), M);         // Dijkstra & DFS
    algorithm_two();                            // calculate the time spent
    dijkstra_cut(dijkstra_one_row(G, M), G, M); // Dijkstra & Edge Cutting
    algorithm_three();                          // calculate the time spent
    return 0;
}
