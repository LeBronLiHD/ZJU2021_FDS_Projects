/*
 * @Author: your name
 * @Date: 2021-12-16 23:47:24
 * @LastEditTime: 2021-12-17 06:45:17
 * @LastEditors: Please set LastEditors
 * @Description: 3_Project_Hard
 * @FilePath: \3_Project_Hard\basic_operation.h
 */

#include "data_structure.h"
#include "input_output.h"

#pragma once

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void search_second(PATHSET *P)
{
    if (P->next == NULL)
    {
        printf("Only One Path!!!!!");
        return;
    }
    PATH *first = P->current;
    PATH *second = P->current;
    PATHSET *ptr = P;
    while (ptr)
    {
        if (ptr->current->length >= first->length && ptr->current->length < second->length)
        {
            second = ptr->current;
        }
        if (ptr->current->length < first->length && ptr->current->length < second->length)
        {
            second = first;
            first = ptr->current;
        }
        ptr = ptr->next;
    }
    show_path_length(second);
}
