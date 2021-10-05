/*
 * @Author: LeBronLiHD
 * @Date: 2021-09-25 20:14:35
 * @LastEditTime: 2021-10-05 18:56:20
 * @LastEditors: Please set LastEditors
 * @Description: Declaration of structs and global variables
 * @FilePath: \1_Project_Hard\parameters.h
 */

#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @description: repeat the function calls for K times to obtain a total run time, 
 *               to avoid runing so quickly that it takes less than a tick to finish
 * @param {*}
 * @return {*}
 */
int K = 1;

/**
 * @description: the scale of matrix(N*N)
 * @param {*}
 * @return {*}
 */
int N = 0;

/**
 * @description: initialize every element of matrix manually or automatically
 * @param {*}
 * @return {*}
 */
int IS_MANUAL_OR_AUTO = 0;

/**
 * @description: struct POINT, just x and y
 * @param {int x, int y}
 * @return {*}
 */
typedef struct POINT
{
    int x;
    int y;
} POINT;

/**
 * @description: struct MATRIX, contains basic infomation and the value of matrix
 * @param {int **VALUE, int COLUMN, int ROW, POINT LeftUp, POINT RightDown}
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
 * @description: struct SUBMAT, describe a rectangular to represent submatrix
 * @param {POINT LeftUp, POINT RightDown}
 * @return {*}
 */
typedef struct SUBMAT
{
    POINT LeftUp;
    POINT RightDown;
} SUBMAT;

/**
 * @description: Declaration of INIT_POINT, START_TIME, END_TIME and TIME_COST
 * @param {*}
 * @return {*}
 */
POINT INIT_POINT = {0, 0};
static clock_t START_TIME;
static clock_t END_TIME;
static clock_t TIME_COST;

/**
 * @description: Declaration of struct TIME_CHAIN, a linked list of time nodes
 * @param {clock_t CurTime, int TimeNode and struct TIME_CHAIN *NextTime}
 * @return {*}
 */
typedef struct TIME_CHAIN
{
    clock_t CurTime;
    int TimeNode;
    struct TIME_CHAIN *NextTime;
} * TIME_CHAIN;
TIME_CHAIN DUMMY_TIME, CUR_TIME;
