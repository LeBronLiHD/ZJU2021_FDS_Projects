/*
 * @Author: LeBronLiHD
 * @Date: 2021-10-03 21:14:53
 * @LastEditTime: 2021-10-05 13:28:41
 * @LastEditors: Please set LastEditors
 * @Description: Calculate the time spent in different solutions
 * @FilePath: \1_Project_Hard\docu_clock.h
 */

#pragma once

#include "parameters.h"

/**
 * @description: Initialize the linked list with a dummy head to store time nodes
 * @param {*}
 * @return {*}
 */
void init_clock()
{
    DUMMY_TIME = (TIME_CHAIN)malloc(sizeof(TIME_CHAIN));
    DUMMY_TIME->CurTime = clock();  // initialize dummy head
    DUMMY_TIME->TimeNode = 0;
    DUMMY_TIME->NextTime = NULL;
    CUR_TIME = DUMMY_TIME;
}

/**
 * @description: Get current time and store it in a new time node
 * @param {*}
 * @return {*}
 */
void get_cur_time()
{
    TIME_CHAIN newTime = (TIME_CHAIN)malloc(sizeof(TIME_CHAIN));
    newTime->CurTime = clock();                 // get current time
    newTime->TimeNode = CUR_TIME->TimeNode + 1; // document the number of time nodes
    newTime->NextTime = NULL;
    CUR_TIME->NextTime = newTime;               // linked into the TIME_CHAIN
    CUR_TIME = newTime;
}

/**
 * @description: Calculate the time spent in different algorithms and display them
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
               CUR_TIME->TimeNode,  // the sequence number of time node
               ((double)CUR_TIME->NextTime->CurTime - (double)CUR_TIME->CurTime),   // calculate the time ticks
               ((double)CUR_TIME->NextTime->CurTime - (double)CUR_TIME->CurTime) / (double)CLOCKS_PER_SEC);
        CUR_TIME = CUR_TIME->NextTime;
    }
}

/**
 * @description: get the time when algorithm start, used for single solution
 * @param {*}
 * @return {*}
 */
void algorithm_start()
{
    START_TIME = clock();
    printf("\nSTART_TIME \t= %.4f s\n", (double)START_TIME / (double)CLOCKS_PER_SEC);
}

/**
 * @description: get the time when algorithm finished, used for single solution
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

