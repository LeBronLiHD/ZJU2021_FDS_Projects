/*
 * @Author: your name
 * @Date: 2021-12-16 17:03:05
 * @LastEditTime: 2021-12-21 01:49:18
 * @LastEditors: Please set LastEditors
 * @Description: main function of 3_Project_Hard
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
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
int main()
{
    scanf("%d %d", &M, &N);
    G = read_graph(M, N);
    program_start();
    PATHSET *P = basic_dfs(G, M);
    search_second(P, 0);
    algorithm_one();
    PATH **D = dijkstra(G, M);
    dijkstra_second(D, M);
    algorithm_two();
    PATH *O = dijkstra_one_row(G, M);
    algorithm_three();
    return 0;
}
