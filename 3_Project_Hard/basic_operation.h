/*
 * @Author: your name
 * @Date: 2021-12-16 23:47:24
 * @LastEditTime: 2021-12-17 20:19:22
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

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void search_all(PATHSET *P, PATH **D, PATH *CP, int start, int M)
{
    for (int i = 0; i < M; i++)
    {
        if (D[start][i].length < INT_MAX)
        {
            bool not_visit = TRUE;
            STEP *ptr = CP->path, *ptr_dij = D[start][i].path;
            while (ptr != NULL && not_visit == TRUE)
            {
                for (ptr_dij = D[start][i].path; ptr_dij != NULL; ptr_dij = ptr_dij->next)
                {
                    if (ptr->point == ptr_dij->point)
                    {
                        not_visit = FALSE;
                        break;
                    }
                }
                ptr = ptr->next;
            }
            if (not_visit)
            {
                CP->path->next = D[start][i].path;
                CP->length += D[start][i].length;
            }
            if (i == M - 1)
            {
                PATHSET *new = (PATHSET *)malloc(sizeof(struct PathSet));
                new->current = CP;
                new->next = NULL;
                if (P == NULL)
                {
                    P = new;
                }
                else
                {
                    P->next = new;
                }
            }
            search_all(P, D, CP, i, M);
        }
        else
        {
            continue;
        }
    }
}

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
void dijkstra_second(PATH **D, int M)
{
    int min_len = D[0][M - 1].length;
    PATHSET *P;
    P = (PATHSET *)malloc(sizeof(struct PathSet));
    P->current = NULL;
    P->next = NULL;
    PATH *CP = (PATH *)malloc(sizeof(struct Path));
    CP->length = 0;
    CP->path->point = 0;
    CP->path->next = NULL;
    search_all(P, D, CP, 0, M);
    search_second(P);
}
