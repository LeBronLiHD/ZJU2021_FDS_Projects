/*
 * @Author: your name
 * @Date: 2021-12-19 19:34:44
 * @LastEditTime: 2021-12-21 18:56:28
 * @LastEditors: Please set LastEditors
 * @Description: file for timer
 * @FilePath: \3_Project_Hard\clock.h
 */

#include "data_structure.h"

#pragma once

/**
 * @description: get current time and store it as beginning time
 * @param {*}
 * @return {*}
 */
void program_start()
{
    START = clock();
}

/**
 * @description: get the time when algorithm one finished
 * @param {*}
 * @return {*}
 */
void algorithm_one()
{
    ONE = clock();
    printf("Algorithm <1> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)ONE - (double)START, ((double)ONE - (double)START) / (double)CLOCKS_PER_SEC);
}

/**
 * @description: get the time when algorithm two finished
 * @param {*}
 * @return {*}
 */
void algorithm_two()
{
    TWO = clock();
    printf("Algorithm <2> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)TWO - (double)ONE, ((double)TWO - (double)ONE) / (double)CLOCKS_PER_SEC);
}

/**
 * @description: get the time when algorithm three finished
 * @param {*}
 * @return {*}
 */
void algorithm_three()
{
    THREE = clock();
    printf("Algorithm <3> -> Time ticks -> %.4f -> Time cost -> %.4f\n",
           (double)THREE - (double)TWO, ((double)THREE - (double)TWO) / (double)CLOCKS_PER_SEC);
}
