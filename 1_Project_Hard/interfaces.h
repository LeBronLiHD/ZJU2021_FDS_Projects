/*
 * @Author: your name
 * @Date: 2021-09-25 19:55:19
 * @LastEditTime: 2021-10-05 10:52:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\headerfile.h
 */

#pragma once

#include "docu_clock.h"

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
int get_random_number()
{
    return rand() % 101 - 50;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void init_matrix(MATRIX *M)
{
    printf("\nInput the Value of N -> ");
    scanf("%d", &N);
    printf("Is Manually(1) or Automatically(0) -> ");
    scanf("%d", &IS_MANUAL_OR_AUTO);
    switch (IS_MANUAL_OR_AUTO)
    {
    case 0:
        printf("\nN = %d, Automatically", N);
        break;
    case 1:
        printf("\nN = %d, Manually", N);
        break;
    default:
        printf("E: file:interfaces.h line:54 Only 0 and 1 wanted!");
        break;
    }
    M->COLUMN = N;   // init
    M->ROW = N;      // init
    M->VALUE = NULL; // init
    M->LeftUp = INIT_POINT;
    M->RightDown = INIT_POINT;
    init_clock();
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void read_matrix_manually(MATRIX *M)
{
    printf("\nInput Matrix Manually -> %d*%d\n", N, N);
    M->VALUE = (int **)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        M->VALUE[i] = (int *)malloc(sizeof(int) * N);
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
void read_matrix_automatically(MATRIX *M)
{
    printf("\nInput Matrix Automatically -> %d*%d\n", N, N);
    M->VALUE = (int **)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        M->VALUE[i] = (int *)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int unit;
            unit = get_random_number();
            M->VALUE[i][j] = unit;
        }
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void read_matrix(MATRIX *M)
{
    switch (IS_MANUAL_OR_AUTO)
    {
    case 0:
        read_matrix_automatically(M);
        break;
    case 1:
        read_matrix_manually(M);
        break;
    default:
        printf("E: file:interfaces.h line:129 Only 0 and 1 wanted!");
        break;
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void print_matrix(const MATRIX *MAT)
{
    printf("\nDisplay Matrix -> %d*%d\n", N, N);
    for (int i = 0; i < MAT->ROW; i++)
    {
        for (int j = 0; j < MAT->COLUMN; j++)
        {
            printf("%d \t ", MAT->VALUE[i][j]);
        }
        printf("\n");
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
int max_element(const MATRIX *MAT)
{
    int MaxEle = MAT->VALUE[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAT->VALUE[i][j] > MaxEle)
            {
                MaxEle = MAT->VALUE[i][j];
            }
        }
    }
    return MaxEle;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
int calculate_sum(const MATRIX *MAT)
{
    int sum = 0;
    for (int i = MAT->LeftUp.x; i <= MAT->RightDown.x; i++)
    {
        for (int j = MAT->LeftUp.y; j <= MAT->RightDown.y; j++)
        {
            sum += MAT->VALUE[i][j];
        }
    }
    return sum;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void update_submatrix_value(SUBMAT *MaxSub, int x1, int y1, int x2, int y2)
{
    MaxSub->LeftUp.x = x1;
    MaxSub->LeftUp.y = y1;
    MaxSub->RightDown.x = x2;
    MaxSub->RightDown.y = y2;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void copy_points(SUBMAT *SubMat, MATRIX *M)
{
    update_submatrix_value(SubMat, M->LeftUp.x, M->LeftUp.y, M->RightDown.x, M->RightDown.y);
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void copy_submatrix(SUBMAT *MaxSub, MATRIX *M)
{
    M->LeftUp.x = MaxSub->LeftUp.x;
    M->LeftUp.y = MaxSub->LeftUp.y;
    M->RightDown.x = MaxSub->RightDown.x;
    M->RightDown.y = MaxSub->RightDown.y;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void update_submatrix_point(SUBMAT *MaxSub, POINT *LeftUp, POINT *RightDown)
{
    update_submatrix_value(MaxSub, LeftUp->x, LeftUp->y, RightDown->x, RightDown->y);
}
