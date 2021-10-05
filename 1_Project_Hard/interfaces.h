/*
 * @Author: LeBronLiHD
 * @Date: 2021-09-25 19:55:19
 * @LastEditTime: 2021-10-05 19:39:29
 * @LastEditors: Please set LastEditors
 * @Description: Some functions to support algorithm in higher layer
 * @FilePath: \1_Project_Hard\headerfile.h
 */

#pragma once

#include "docu_clock.h"

/**
 * @description: simple hello_world function to test CMake build
 * @param {*}
 * @return {*}
 */
void hello_world()
{
    printf("Hello world!\n");
}

/**
 * @description: get random number from -50 to 50
 * @param {*}
 * @return {int random number}
 */
int get_random_number()
{
    int seed = rand() % 101 - 50; // Definition of seed
    srand(seed);                  // srand the seed to ensure randomness
    return rand() % 101 - 50;     // rand() % 101 -> 0 ~ 100
                                  // rand() % 101 - 50 -> -50 ~ 50
}

/**
 * @description: Initialize the basic infomation(rows, columns, etc.) of M, N and IS_MANUAL_OR_AUTO
 * @param {MATRIX *M}
 * @return {*}
 */
void init_matrix(MATRIX *M)
{
    printf("\nInput the Value of N -> ");
    scanf("%d", &N);
    printf("\nInput the Value of K -> ");
    scanf("%d", &K);
    printf("\nIs Manually(1) or Automatically(0) -> ");
    scanf("%d", &IS_MANUAL_OR_AUTO);
    switch (IS_MANUAL_OR_AUTO)
    {
    case 0:
        printf("\nN = %d, Automatically, Repeat = %d\n", N, K);
        break;
    case 1:
        printf("\nN = %d, Manually, Repeat = %d\n", N, K);
        break;
    default:
        printf("E: file:interfaces.h line:54 Only 0 and 1 wanted!");
        break;
    }
    M->COLUMN = N;             // initialize COLUMN
    M->ROW = N;                // initialize ROW
    M->VALUE = NULL;           // initialize VALUE
    M->LeftUp = INIT_POINT;    // initialize LeftUp
    M->RightDown = INIT_POINT; // initialize RightDown
    init_clock();              // initialize machine clock
}

/**
 * @description: set the value of every element in matrix manually
 * @param {MATRIX *M}
 * @return {*}
 */
void read_matrix_manually(MATRIX *M)
{
    printf("\nInput Matrix Manually -> %d*%d\n", N, N);
    M->VALUE = (int **)malloc(sizeof(int) * N); // allocate memory space
    int i = 0, j = 0, unit = 0;
    for (i = 0; i < N; i++)
    {
        M->VALUE[i] = (int *)malloc(sizeof(int) * N);
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &unit); // input the value manually
            M->VALUE[i][j] = unit;
        }
    }
}

/**
 * @description: set the value of every element in matrix automatically
 * @param {MATRIX *M}
 * @return {*}
 */
void read_matrix_automatically(MATRIX *M)
{
    printf("\nInput Matrix Automatically -> %d*%d\n", N, N);
    M->VALUE = (int **)malloc(sizeof(int) * SCALE);
    // allocate memory space, use N + 1 to avoid segmentation fault
    int i = 0, j = 0, unit = 0;
    for (i = 0; i < N; i++)
    {
        M->VALUE[i] = (int *)malloc(sizeof(int) * SCALE);
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            unit = get_random_number(); // get the random value
            M->VALUE[i][j] = unit;
        }
    }
}

/**
 * @description: set the value of every element in matrix in selected mode
 * @param {MATRIX *M}
 * @return {*}
 */
void read_matrix(MATRIX *M)
{
    switch (IS_MANUAL_OR_AUTO)
    {
    case 0:
        read_matrix_automatically(M); // set values of matrix automatically
        break;
    case 1:
        read_matrix_manually(M); // set values of matrix manually
        break;
    default:
        printf("E: file:interfaces.h line:132 Only 0 and 1 wanted!");
        break;
    }
}

/**
 * @description: display the matrix we initialized earlier
 * @param {const MATRIX *MAT}
 * @return {*}
 */
void print_matrix(const MATRIX *MAT) // use const for protection
{
    printf("\nDisplay Matrix -> %d*%d\n", N, N);
    int i = 0, j = 0;
    for (i = 0; i < MAT->ROW; i++)
    {
        for (j = 0; j < MAT->COLUMN; j++)
        {
            printf("%d \t ", MAT->VALUE[i][j]);
        }
        printf("\n");
    }
}

/**
 * @description: find the biggest element in the matrix
 * @param {const MATRIX *MAT}
 * @return {int MaxEle}
 */
int max_element(const MATRIX *MAT) // use const for protection
{
    int MaxEle = MAT->VALUE[0][0];
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
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
 * @description: calculate the sum of specific submatrix
 * @param {const MATRIX *MAT}
 * @return {int sum}
 */
int calculate_sum(const MATRIX *MAT) // use const for protection
{
    int sum = 0;
    int i = 0, j = 0;
    for (i = MAT->LeftUp.x; i <= MAT->RightDown.x; i++)
    {
        for (j = MAT->LeftUp.y; j <= MAT->RightDown.y; j++)
        {
            sum += MAT->VALUE[i][j];
        }
    }
    return sum;
}

/**
 * @description: update the variables of specific MaxSub using four integers
 * @param {SUBMAT *MaxSub, int x1, int y1, int x2, int y2}
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
 * @description: update the variables of specific MaxSub by MATRIX M
 * @param {SUBMAT *SubMat, MATRIX *M}
 * @return {*}
 */
void copy_points(SUBMAT *SubMat, MATRIX *M)
{
    update_submatrix_value(SubMat, M->LeftUp.x, M->LeftUp.y, M->RightDown.x, M->RightDown.y);
}

/**
 * @description: update the submatrix range of MATRIX M using SUBMAT MaxSub
 * @param {SUBMAT *MaxSub, MATRIX *M}
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
 * @description: update the variables of specific MaxSub by two POINTs
 * @param {*}
 * @return {*}
 */
void update_submatrix_point(SUBMAT *MaxSub, POINT *LeftUp, POINT *RightDown)
{
    update_submatrix_value(MaxSub, LeftUp->x, LeftUp->y, RightDown->x, RightDown->y);
}
