/*
 * @Author: your name
 * @Date: 2021-12-16 17:03:05
 * @LastEditTime: 2021-12-17 06:15:09
 * @LastEditors: Please set LastEditors
 * @Description: main function of 3_Project_Hard
 * @FilePath: \3_Project_Hard\main.c
 */

#include "input_output.h"
#include "data_structure.h"
#include "algorithm.h"
#include "basic_operation.h"

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
    show_graph(G, M);
    PATHSET *P = basic_bfs(G, M);
    search_second(P);
    return 0;
}
