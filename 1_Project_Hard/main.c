/*
 * @Author: your name
 * @Date: 2021-09-25 19:55:01
 * @LastEditTime: 2021-09-26 13:30:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\main.c
 */

#include "firstsolution.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
int main()
{
    MATRIX M;       // definition
    init_matrix(&M);
    read_matrix(&M);
    print_matrix(M);
    algorithm_start();
    SolutionOne(M);
    algorithm_end();
    return 0;
}
