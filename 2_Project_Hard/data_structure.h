/*
 * @Author: your name
 * @Date: 2021-11-10 13:01:14
 * @LastEditTime: 2021-11-10 13:18:30
 * @LastEditors: Please set LastEditors
 * @Description: definiting specific data structure
 * @FilePath: \2_Project_Hard\data_structure.h
 */

#include <stdio.h>
#include <stdlib.h>

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
 * @description: Data Structure of the Coordination
 * @param {*}
 * @return {*}
 */
typedef struct Point
{
    double x_pos, y_pos;
}* POINT;


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

