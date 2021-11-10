/*
 * @Author: your name
 * @Date: 2021-11-10 18:55:39
 * @LastEditTime: 2021-11-10 22:26:08
 * @LastEditors: Please set LastEditors
 * @Description: APIs of searching tree and the voting table is built here
 * @FilePath: \2_Project_Hard\search_path.h
 */

#pragma once

#include "data_structure.h"
#include "basic_calculation.h"
#include "search_tree.h"

/**
 * @description: Init Voting Table
 * @param int Size
 * @return {*}
 */
SEARCH_PATH InitSearchTree(int Size)
{
    SEARCH_PATH Path = (SEARCH_PATH)malloc(sizeof(struct SearchPath));
    Path->path_one = (int *)malloc(sizeof(int) * Size);
    Path->path_two = (int *)malloc(sizeof(int) * Size);
    Path->path_size = 0;
    return Path;
}

/**
 * @description: judge the validation in two angles
 * @param double cos_one, double cos_two
 * @return int
 */
int valid_in_angle(double cos_one, double cos_two)
{
    return cos_one == cos_two;
}

/**
 * @description: judge the validation in two distances
 * @param double distance_one, double distance_two, double distance_three, double distance_four
 * @return int
 */
int valid_in_length(double distance_one, double distance_two, double distance_three, double distance_four)
{
    return (distance_two - distance_one) * (distance_three - distance_four) < 0;
}

/**
 * @description: find the best match of the searching tree and build the voting table
 * @param POLYGON One, POLYGON Two, int IndexOne, int IndexTwo, SEARCH_PATH SearchPath
 * @return {*}
 */
void SearchBestMatch(POLYGON One, POLYGON Two, int IndexOne, int IndexTwo, SEARCH_PATH SearchPath)
{
    // the number of point in two polygons
    int SizeOne = One->num_of_points;
    int SizeTwo = Two->num_of_points;
    for (int i = IndexOne; i < SizeOne && IndexOne < SizeOne && IndexTwo < SizeTwo; i++)
    {
        for (int j = IndexTwo; j < SizeTwo && IndexOne < SizeOne && IndexTwo < SizeTwo; j++)
        {
            // poll the points of polygon_one and polygon_two
            int SizePath = SearchPath->path_size;
            if (SizePath >= 2)
            {
                // if we have searched more than 2 points, we should judge the validation of the third point
                // calculate the two distances of the corresponding edges in polygon_one
                double distance_one = distance_between_points(One->array_of_points[i], One->array_of_points[SearchPath->path_one[SizePath - 1]]);
                double distance_two = distance_between_points(One->array_of_points[SearchPath->path_one[SizePath - 1]], One->array_of_points[SearchPath->path_one[SizePath - 2]]);
                // calculate the two distances of the corresponding edges in polygon_two
                double distance_three = distance_between_points(Two->array_of_points[j], Two->array_of_points[SearchPath->path_two[SizePath - 1]]);
                double distance_four = distance_between_points(Two->array_of_points[SearchPath->path_two[SizePath - 1]], Two->array_of_points[SearchPath->path_two[SizePath - 2]]);
                if (valid_in_length(distance_one, distance_two, distance_three, distance_four) == 0)
                {
                    // if the length relation of the distances of this four edeges is not valid, pruning
                    continue;
                }
                // calculate the included angle of the two edges in polygon_one
                double cos_one = cos_between_edges(One->array_of_points[i], One->array_of_points[SearchPath->path_one[SizePath - 1]], One->array_of_points[SearchPath->path_one[SizePath - 2]]);
                // calculate the included angle of the two edges in polygon_two
                double cos_two = cos_between_edges(Two->array_of_points[j], Two->array_of_points[SearchPath->path_two[SizePath - 1]], Two->array_of_points[SearchPath->path_two[SizePath - 2]]);
                if (valid_in_angle(cos_one, cos_two) == 0)
                {
                    // if the angle relation of the distances of this four edeges is not valid, pruning
                    continue;
                }
            }
            // if we have not count more than 2 points, just count the current point in
            // or if the new point meet the standard of length and angle before
            push_path(SearchPath, i, j);
            // continue the search process
            SearchBestMatch(One, Two, i + 1, j + 1, SearchPath);
        }
    }
    if (SearchPath->path_size > 2)
    {
        // > 2, means we have the condition to constructure a polygon, then we should vote for corresponding points
        for (int i = 0; i < SearchPath->path_size; i++)
        {
            VOTING_TABLE[SearchPath->path_one[i]][SearchPath->path_two[i]]++;
        }
    }
    if (SearchPath->path_size > 0)
    {
        // pop the last-in point before exit the function
        pop_path(SearchPath);
    }
    return;
}
