/*
 * @Author: your name
 * @Date: 2021-12-19 19:34:44
 * @LastEditTime: 2021-12-21 01:46:31
 * @LastEditors: Please set LastEditors
 * @Description: 3_Project_Hard
 * @FilePath: \3_Project_Hard\clock.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: Get current time and store it in a new time node
 * @param {*}
 * @return {*}
 */
void program_start()
{
    START = clock();
}

/**
 * @description: Get current time and store it in a new time node
 * @param {*}
 * @return {*}
 */
void algorithm_one()
{
    ONE = clock();
    printf("\nAlgorithm <1> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)ONE - (double)START, ((double)ONE - (double)START) / (double)CLOCKS_PER_SEC);
}

/**
 * @description: Get current time and store it in a new time node
 * @param {*}
 * @return {*}
 */
void algorithm_two()
{
    TWO = clock();
    printf("\nAlgorithm <2> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)TWO - (double)ONE, ((double)TWO - (double)ONE) / (double)CLOCKS_PER_SEC);
}

/**
 * @description: Get current time and store it in a new time node
 * @param {*}
 * @return {*}
 */
void algorithm_three()
{
    THREE = clock();
    printf("\nAlgorithm <3> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)THREE - (double)TWO, ((double)THREE - (double)TWO) / (double)CLOCKS_PER_SEC);
}
