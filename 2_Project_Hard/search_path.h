/*
 * @Author: your name
 * @Date: 2021-11-10 18:55:39
 * @LastEditTime: 2021-11-10 21:40:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \2_Project_Hard\search_path.h
 */

#pragma once

#include "data_structure.h"
#include "basic_calculation.h"
#include "search_tree.h"

/**
 * @description: Init Voting Table
 * @param const int M, const int N
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
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
int valid_in_angle(double cos_one, double cos_two)
{
    return cos_one == cos_two;
}

/**
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
int valid_in_length(double distance_one, double distance_two, double distance_three, double distance_four)
{
    return (distance_two - distance_one) * (distance_three - distance_four) < 0;
}

/**
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void SearchBestMatch(POLYGON One, POLYGON Two, int IndexOne, int IndexTwo, SEARCH_PATH SearchPath)
{
    int SizeOne = One->num_of_points;
    int SizeTwo = Two->num_of_points;
    for (int i = IndexOne; i < SizeOne && IndexOne < SizeOne && IndexTwo < SizeTwo; i++)
    {
        for (int j = IndexTwo; j < SizeTwo && IndexOne < SizeOne && IndexTwo < SizeTwo; j++)
        {
            int SizePath = SearchPath->path_size;
            if (SizePath >= 2)
            {
                double distance_one = distance_between_points(One->array_of_points[i], One->array_of_points[SearchPath->path_one[SizePath - 1]]);
                double distance_two = distance_between_points(One->array_of_points[SearchPath->path_one[SizePath - 1]], One->array_of_points[SearchPath->path_one[SizePath - 2]]);
                double distance_three = distance_between_points(Two->array_of_points[j], Two->array_of_points[SearchPath->path_two[SizePath - 1]]);
                double distance_four = distance_between_points(Two->array_of_points[SearchPath->path_two[SizePath - 1]], Two->array_of_points[SearchPath->path_two[SizePath - 2]]);
                if (valid_in_length(distance_one, distance_two, distance_three, distance_four) == 0)
                {
                    continue;
                }
                double cos_one = cos_between_edges(One->array_of_points[i], One->array_of_points[SearchPath->path_one[SizePath - 1]], One->array_of_points[SearchPath->path_one[SizePath - 2]]);
                double cos_two = cos_between_edges(Two->array_of_points[j], Two->array_of_points[SearchPath->path_two[SizePath - 1]], Two->array_of_points[SearchPath->path_two[SizePath - 2]]);
                if (valid_in_angle(cos_one, cos_two) == 0)
                {
                    continue;
                }
            }
            push_path(SearchPath, i, j);
            SearchBestMatch(One, Two, i + 1, j + 1, SearchPath);
        }
    }
    if (SearchPath->path_size > 2)
    {
        for (int i = 0; i < SearchPath->path_size; i++)
        {
            VOTING_TABLE[SearchPath->path_one[i]][SearchPath->path_two[i]]++;
        }
    }
    if (SearchPath->path_size > 0)
    {
        pop_path(SearchPath);
    }
    return;
}
