/*
 * @Author: your name
 * @Date: 2021-11-10 13:39:57
 * @LastEditTime: 2021-11-10 20:13:58
 * @LastEditors: Please set LastEditors
 * @Description: Init and Show the Polygon
 * @FilePath: \2_Project_Hard\init_polygon.h
 */

#pragma once

#include "data_structure.h"

/**
 * @description: Initialize the Polygon
 * @param const int Num
 * @return POLYGON Poly
 */
POLYGON InitPolygon(const int Num)
{
    POLYGON Poly = (POLYGON)malloc(sizeof(struct Polygon));
    Poly->num_of_points = Num;
    Poly->array_of_points = (POINT *)malloc(sizeof(POINT) * Num);
    for (int i = 0; i < Num; i++)
    {
        Poly->array_of_points[i] = (POINT)malloc(sizeof(struct Point));
    }
    for (int i = 0; i < Num; i++)
    {
        double x, y;
        scanf("%lf", &x);
        scanf("%lf", &y);
        Poly->array_of_points[i]->x_pos = x;
        Poly->array_of_points[i]->y_pos = y;
        Poly->array_of_points[i]->index = i + 1;
    }
    return Poly;
}

/**
 * @description: Show the Polygon
 * @param POLYGON Poly
 * @return {*}
 */
void DisplayPoly(POLYGON Poly)
{
    printf("Number of Points -> %d\n", Poly->num_of_points);
    for (int i = 0; i < Poly->num_of_points; i++)
    {
        printf("Point %d -> (%.2f, %.2f) -> index %d\n", i + 1,
               Poly->array_of_points[i]->x_pos,
               Poly->array_of_points[i]->y_pos,
               Poly->array_of_points[i]->index);
    }
    return;
}
