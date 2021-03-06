/*
 * @Author: your name
 * @Date: 2021-11-10 18:38:58
 * @LastEditTime: 2021-11-10 22:07:55
 * @LastEditors: Please set LastEditors
 * @Description: Basic Mathmatical Calculation
 * @FilePath: \2_Project_Hard\basic_calculation.h
 */

#pragma once

#include "data_structure.h"
#include "math.h"

/**
 * @description: calculate the distance of two points
 * @param POINT One, POINT Two
 * @return double
 */
double distance_between_points(POINT One, POINT Two)
{
    return sqrt(pow(One->x_pos - Two->x_pos, 2) + pow(One->y_pos - Two->y_pos, 2));
}

/**
 * @description: calculate the inner product of two vectors
 * @param VECTOR One, VECTOR Two
 * @return double
 */
double inner_product(VECTOR One, VECTOR Two)
{
    return One->x_dis * Two->x_dis + One->y_dis * Two->y_dis;
}

/**
 * @description: calculate the length of the vector
 * @param VECTOR Vec
 * @return double
 */
double length_of_vector(VECTOR Vec)
{
    return sqrt(pow(Vec->x_dis, 2) + pow(Vec->y_dis, 2));
}

/**
 * @description: calculate the cos value of angle of two vectors
 * @param POINT Left, POINT Middle, POINT Right
 * @return double
 */
double cos_between_edges(POINT Left, POINT Middle, POINT Right)
{
    VECTOR One = (VECTOR)malloc(sizeof(struct Vector));
    VECTOR Two = (VECTOR)malloc(sizeof(struct Vector));
    One->x_dis = Middle->x_pos - Left->x_pos;
    One->y_dis = Middle->y_pos - Left->y_pos;
    Two->x_dis = Right->x_pos - Middle->x_pos;
    Two->y_dis = Right->y_pos - Middle->y_pos;
    return inner_product(One, Two) / (length_of_vector(One) * length_of_vector(Two));
}
