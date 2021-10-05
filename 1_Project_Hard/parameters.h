/*
 * @Author: your name
 * @Date: 2021-09-25 20:14:35
 * @LastEditTime: 2021-10-05 10:50:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\parameters.h
 */

#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
int N = 0;
int IS_MANUAL_OR_AUTO = 0;

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
    POINT LeftUp;
    POINT RightDown;
} SUBMAT;

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
POINT INIT_POINT = {0, 0};
static clock_t START_TIME;
static clock_t END_TIME;
static clock_t TIME_COST;

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
typedef struct TIME_CHAIN
{
    clock_t CurTime;
    int TimeNode;
    struct TIME_CHAIN *NextTime;
} * TIME_CHAIN;
TIME_CHAIN DUMMY_TIME, CUR_TIME;
