/*
 * @Author: your name
 * @Date: 2021-11-10 13:01:14
 * @LastEditTime: 2021-11-10 22:16:04
 * @LastEditors: Please set LastEditors
 * @Description: definiting specific data structure
 * @FilePath: \2_Project_Hard\data_structure.h
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>

int** VOTING_TABLE = NULL;

/**
 * @description: Data Structure of the Search Path of Search Tree
 * @param {*}
 * @return {*}
 */
typedef struct SearchPath
{
    int *path_one, *path_two;
    int path_size;
}*SEARCH_PATH;

/**
 * @description: Data Structure of the Final Output
 * @param {*}
 * @return {*}
 */
typedef struct OutputList
{
    int index_one, index_two;
    struct OutputList* next_output;
}* OUTPUT_LIST;

/**
 * @description: Data Structure of the Coordination Point
 * @param {*}
 * @return {*}
 */
typedef struct Point
{
    double x_pos, y_pos;
    int index;
}* POINT;

/**
 * @description: Data Structure of the Vector
 * @param {*}
 * @return {*}
 */
typedef struct Vector
{
    double x_dis, y_dis;
}* VECTOR;

/**
 * @description: Data Structure of the Polygon
 * @param {*}
 * @return {*}
 */
typedef struct Polygon
{
    int num_of_points;
    POINT* array_of_points;
}* POLYGON;

