/*
 * @Author: your name
 * @Date: 2021-12-16 23:41:00
 * @LastEditTime: 2021-12-21 19:07:36
 * @LastEditors: Please set LastEditors
 * @Description: global parameters and special data structures
 * @FilePath: \3_Project_Hard\data_structure.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma once

/**
 * @description: bool type
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
 * @description: the steps of the path
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
 * @description: made of STEP* and the length of the path
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
 * @description: a set of paths
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
 * @description: record the shortest length and 2-nd shortest length
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
 * @description: global parameters for timer
 * @param {*}
 * @return {*}
 */
static clock_t START;
static clock_t ONE;
static clock_t TWO;
static clock_t THREE;
