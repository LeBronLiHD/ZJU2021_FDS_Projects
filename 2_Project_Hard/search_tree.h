/*
 * @Author: your name
 * @Date: 2021-11-10 15:38:32
 * @LastEditTime: 2021-11-10 18:42:16
 * @LastEditors: Please set LastEditors
 * @Description: API of Search Tree
 * @FilePath: \2_Project_Hard\search_tree.h
 */

#pragma once

#include "data_structure.h"

/**
 * @description: Display Current Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void push_path(SEARCH_PATH SearchPath, int IndexOne, int IndexTwo)
{
    SearchPath->path_one[SearchPath->path_size] = IndexOne;
    SearchPath->path_two[SearchPath->path_size] = IndexTwo;
    SearchPath->path_size++;
}

/**
 * @description: Display Current Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void pop_path(SEARCH_PATH SearchPath)
{
    SearchPath->path_size--;
}
