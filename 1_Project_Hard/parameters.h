/*
 * @Author: your name
 * @Date: 2021-09-25 20:14:35
 * @LastEditTime: 2021-09-27 09:07:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\parameters.h
 */

#include <time.h>

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
typedef struct POINT
{
    int x;
    int y;
} POINT;

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
typedef struct MATRIX
{
    int **VALUE;
    int COLUMN;
    int ROW;
    POINT LeftUp;
    POINT RightDown;
} MATRIX;

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
typedef struct SUBMAT
{
    POINT X;
    POINT Y;
} SUBMAT;

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
const int N = 5;
static clock_t START_TIME;
static clock_t END_TIME;
static clock_t TIME_COST;

POINT INIT00 = {0, 0};

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void algorithm_start()
{
    START_TIME = clock();
    printf("\nSTART_TIME \t= %.4f s\n", (double)START_TIME / (double)CLK_TCK);
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void algorithm_end()
{
    END_TIME = clock();
    printf("\nEND_TIME \t= %.4f s\n", (double)END_TIME / (double)CLK_TCK);
    TIME_COST = END_TIME - START_TIME;
    printf("TIME_COST \t= %.4f s\n", (double)TIME_COST / (double)CLK_TCK);
}

/**
 * @description: Test Cases
 * @return int**
 * 0 -2 -7 0
 * 9 2 -6 2
 * -4 1 -4 1
 * -1 8 0 -2
 */
