/*
 * @Author: your name
 * @Date: 2021-11-10 15:38:32
 * @LastEditTime: 2021-11-10 22:07:57
 * @LastEditors: Please set LastEditors
 * @Description: APIs of Search Tree
 * @FilePath: \2_Project_Hard\search_tree.h
 */

#pragma once

#include "data_structure.h"

/**
 * @description: push new pair of points to the searching tree
 * @param SEARCH_PATH SearchPath, int IndexOne, int IndexTwo
 * @return {*}
 */
void push_path(SEARCH_PATH SearchPath, int IndexOne, int IndexTwo)
{
    SearchPath->path_one[SearchPath->path_size] = IndexOne;
    SearchPath->path_two[SearchPath->path_size] = IndexTwo;
    SearchPath->path_size++;
}

/**
 * @description: pop the last-in pair of the searching tree
 * @param SEARCH_PATH SearchPath
 * @return {*}
 */
void pop_path(SEARCH_PATH SearchPath)
{
    SearchPath->path_size--;
}
