/*
 * @Author: your name
 * @Date: 2021-09-25 19:55:19
 * @LastEditTime: 2021-09-27 09:06:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\headerfile.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void hello_world()
{
    printf("Hello world!\n");
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void init_matrix(MATRIX *M)
{
    M->COLUMN = N;   // init
    M->ROW = N;      // init
    M->VALUE = NULL; // init
    M->LeftUp = INIT00;
    M->RightDown = INIT00;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void **read_matrix(MATRIX* M)
{
    printf("\nInput Matrix -> %d*%d\n", N, N);
    M->VALUE = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        M->VALUE[i] = malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int unit;
            scanf("%d", &unit);
            M->VALUE[i][j] = unit;
        }
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void print_matrix(MATRIX MAT)
{
    printf("\nDisplay Matrix -> %d*%d\n", N, N);
    for (int i = 0; i < MAT.ROW; i++)
    {
        for (int j = 0; j < MAT.COLUMN; j++)
        {
            printf("%d \t ", MAT.VALUE[i][j]);
        }
        printf("\n");
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
int calculate_sum(MATRIX MAT)
{
    int sum = 0;
    for (int i = MAT.LeftUp.x; i <= MAT.RightDown.x; i++)
    {
        for (int j = MAT.LeftUp.y; j <= MAT.RightDown.y; j++)
        {
            sum += MAT.VALUE[i][j];
        }
    }
    return sum;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void copy_points(SUBMAT* SubMat, MATRIX* M)
{
    SubMat->X.x = M->LeftUp.x;
    SubMat->X.y = M->LeftUp.y;
    SubMat->Y.x = M->RightDown.x;
    SubMat->Y.y = M->RightDown.y;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void copy_submatrix(SUBMAT* MaxSub, MATRIX* M)
{
    M->LeftUp.x = MaxSub->X.x;
    M->LeftUp.y = MaxSub->X.y;
    M->RightDown.x = MaxSub->Y.x;
    M->RightDown.y = MaxSub->Y.y;
}
