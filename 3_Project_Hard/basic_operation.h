/*
 * @Author: your name
 * @Date: 2021-12-16 23:47:24
 * @LastEditTime: 2021-12-21 01:39:50
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
void search_second(PATHSET *P, int mode)
{
    if (mode == 0)
    {
        printf("dfs -> ");
    }
    else
    {
        printf("dij -> ");
    }
    if (P == NULL || P->next == NULL)
    {
        printf("Less than 2 Paths!!!!!");
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
                    if (ptr->point == ptr_dij->point && ptr_dij->point != start)
                    {
                        not_visit = FALSE;
                        break;
                    }
                }
                ptr = ptr->next;
            }
            if (not_visit == FALSE)
            {
                continue;
            }
            STEP *cp_tail = CP->path;
            while (cp_tail && cp_tail->next)
            {
                cp_tail = cp_tail->next;
            }
            if (not_visit)
            {
                STEP *ptr_path = cp_tail;
                STEP *copy_path = D[start][i].path;
                while (copy_path)
                {
                    STEP *new_copy = (STEP *)malloc(sizeof(struct Step));
                    new_copy->point = copy_path->point;
                    new_copy->next = NULL;
                    if (CP->path == NULL)
                    {
                        CP->path = new_copy;
                        ptr_path = CP->path;
                        copy_path = copy_path->next;
                    }
                    else
                    {
                        ptr_path->next = new_copy;
                        ptr_path = new_copy;
                        copy_path = copy_path->next;
                    }
                }
                CP->length += D[start][i].length;
            }
            if (i == M - 1)
            {
                PATHSET *new = (PATHSET *)malloc(sizeof(struct PathSet));
                new->current = (PATH *)malloc(sizeof(struct Path));
                new->current = NULL;
                STEP *ptr_new = CP->path, *ptr_new_path = new->current->path;
                while (ptr_new)
                {
                    if (ptr_new_path == NULL)
                    {
                        new->current->path = ptr_new;
                        ptr_new_path = new->current->path;
                    }
                    else
                    {
                        STEP *new_step = (STEP *)malloc(sizeof(struct Step));
                        new_step->point = ptr_new->point;
                        new_step->next = NULL;
                        ptr_new_path->next = new_step;
                        ptr_new_path = new_step;
                    }
                    ptr_new = ptr_new->next;
                }
                new->next = NULL;
                if (P == NULL)
                {
                    P = new;
                }
                else
                {
                    PATHSET *ptr_p = P;
                    while (ptr_p->next)
                    {
                        ptr_p = ptr_p->next;
                    }
                    ptr_p->next = new;
                }
            }
            search_all(P, D, CP, i + 1, M);
            if (cp_tail != NULL)
            {
                cp_tail->next = NULL;
                CP->length -= D[start][i].length;
            }
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
    P->current = (PATH *)malloc(sizeof(struct Path));
    P->current = NULL;
    P->next = NULL;
    PATH *CP = (PATH *)malloc(sizeof(struct Path));
    CP->length = 0;
    CP->path = (STEP *)malloc(sizeof(struct Step));
    CP->path = NULL;
    search_all(P, D, CP, 0, M);
    search_second(P, 1);
}
