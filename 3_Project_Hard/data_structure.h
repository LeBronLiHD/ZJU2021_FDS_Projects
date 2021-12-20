/*
 * @Author: your name
 * @Date: 2021-12-16 23:41:00
 * @LastEditTime: 2021-12-21 01:46:22
 * @LastEditors: Please set LastEditors
 * @Description: 3_Project_Hard
 * @FilePath: \3_Project_Hard\data_structure.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma once

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
enum bool
{
    FALSE,
    TRUE
};
typedef enum bool bool;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
struct Step
{
    int point;
    struct Step *next;
};
typedef struct Step STEP;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
struct Path
{
    STEP *path;
    int length;
};
typedef struct Path PATH;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
struct PathSet
{
    PATH *current;
    struct PathSet *next;
};
typedef struct PathSet PATHSET;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
struct Record
{
    int min;
    int second_min;
    bool second_exist;
};
typedef struct Record RECORD;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
static clock_t START;
static clock_t ONE;
static clock_t TWO;
static clock_t THREE;
