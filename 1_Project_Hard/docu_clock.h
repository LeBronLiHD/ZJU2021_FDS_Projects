/*
 * @Author: your name
 * @Date: 2021-10-03 21:14:53
 * @LastEditTime: 2021-10-03 22:00:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\docu_clock.h
 */

#pragma once

#include "parameters.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void init_clock()
{
    DUMMY_TIME = (TIME_CHAIN)malloc(sizeof(TIME_CHAIN));
    DUMMY_TIME->CurTime = clock();
    DUMMY_TIME->TimeNode = 0;
    DUMMY_TIME->NextTime = NULL;
    CUR_TIME = DUMMY_TIME;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void get_cur_time()
{
    TIME_CHAIN newTime = (TIME_CHAIN)malloc(sizeof(TIME_CHAIN));
    newTime->CurTime = clock();
    newTime->TimeNode = CUR_TIME->TimeNode + 1;
    newTime->NextTime = NULL;
    CUR_TIME->NextTime = newTime;
    CUR_TIME = newTime;
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void display_time()
{
    CUR_TIME = DUMMY_TIME->NextTime;
    printf("\nDisplay Time:\n");
    while (CUR_TIME->NextTime != NULL)
    {
        printf("Algorithm <%d>\t Time Ticks Cost = %.4f\t Time Total = %.4f s\n",
               CUR_TIME->TimeNode,
               ((double)CUR_TIME->NextTime->CurTime - (double)CUR_TIME->CurTime),
               ((double)CUR_TIME->NextTime->CurTime - (double)CUR_TIME->CurTime) / (double)CLOCKS_PER_SEC);
        CUR_TIME = CUR_TIME->NextTime;
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void algorithm_start()
{
    START_TIME = clock();
    printf("\nSTART_TIME \t= %.4f s\n", (double)START_TIME / (double)CLOCKS_PER_SEC);
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void algorithm_end()
{
    END_TIME = clock();
    printf("\nEND_TIME \t= %.4f s\n", (double)END_TIME / (double)CLOCKS_PER_SEC);
    TIME_COST = END_TIME - START_TIME;
    printf("TIME_COST \t= %.4f s\n", (double)TIME_COST / (double)CLOCKS_PER_SEC);
}

