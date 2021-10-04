/*
 * @Author: your name
 * @Date: 2021-09-25 19:55:01
 * @LastEditTime: 2021-10-04 09:36:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\main.c
 */

#include "firstsolution.h"
#include "secondsolution.h"
#include "thirdsolution.h"

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
    print_matrix(&M);
    get_cur_time();
    solution_one(M);
    get_cur_time();
    solution_two(M);
    get_cur_time();
    solution_three(M);
    get_cur_time();
    display_time();
    return 0;
}
