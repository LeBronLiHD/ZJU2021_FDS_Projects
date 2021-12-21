/*
 * @Author: your name
 * @Date: 2021-12-16 23:47:24
 * @LastEditTime: 2021-12-21 21:31:49
 * @LastEditors: Please set LastEditors
 * @Description: some basic function such as sorting
 * @FilePath: \3_Project_Hard\basic_operation.h
 */

#include "data_structure.h"
#include "input_output.h"

#pragma once

/**
 * @description: find the second path from all valid paths
 * @param {PATHSET *P, int mode}
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
    if (P == NULL || P->next == NULL) // check if there is at least two paths
    {
        printf("Less than 2 Paths!!!!!\n");
        return;
    }
    PATH *first = P->current;
    PATH *second = P->current;
    PATHSET *ptr = P;
    while (ptr)
    {
        if (ptr->current->length >= second->length && first == second)
        {
            // if the first and second point to the same memory and we get a longer path
            second = ptr->current;
        }
        if (ptr->current->length >= first->length && ptr->current->length < second->length)
        {
            // if the distance is longer than the shortest but smaller than the 2-nd shortest
            second = ptr->current;
        }
        if (ptr->current->length < first->length && ptr->current->length < second->length)
        {
            // if the distance is smaller than the current shortest
            second = first;
            first = ptr->current;
        }
        ptr = ptr->next;
    }
    show_path_length(second);
}

/**
 * @description: search all valid paths from 1 to M based on matrix D
 * @param {PATHSET *P, PATH **D, PATH *CP, int start, int M}
 * @return {*}
 */
void search_all(PATHSET *P, PATH **D, PATH *CP, int start, int M)
{
    for (int i = 0; i < M; i++)
    {
        if (i == start)
        {
            continue; // if it is start node, continue
        }
        if (D[start][i].length < INT_MAX)
        {
            // if we have calculated one way from start to i
            // we first check if we have visited this node before
            bool not_visit = TRUE;
            STEP *ptr = CP->path, *ptr_dij = D[start][i].path;
            while (ptr != NULL && not_visit == TRUE)
            {
                for (ptr_dij = D[start][i].path; ptr_dij != NULL; ptr_dij = ptr_dij->next)
                {
                    if (ptr->point == ptr_dij->point && ptr_dij->point != start)
                    {
                        // if we find same node except the start node, then we assume the node visited
                        not_visit = FALSE;
                        break;
                    }
                    if (ptr_dij->point == M - 1 && ptr_dij->next != NULL)
                    {
                        // if the path from start to i have M included, pruning
                        not_visit = FALSE;
                        break;
                    }
                }
                ptr = ptr->next;
            }
            if (not_visit == FALSE)
            {
                continue; // if visited, continue
            }
            STEP *cp_tail = CP->path;
            while (cp_tail->next)
            {
                cp_tail = cp_tail->next; // locate the tail node of CP(current path)
            }
            if (not_visit)
            {
                // if not visited, we append the path from start to i as part of the path from 1 to M
                STEP *ptr_path = cp_tail;
                STEP *copy_path = D[start][i].path->next;
                while (copy_path)
                {
                    STEP *new_copy = (STEP *)malloc(sizeof(struct Step)); // allocate space
                    new_copy->point = copy_path->point;                   // copy the values
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
                CP->length += D[start][i].length; // update the length
            }
            if (i == M - 1)
            {
                // if we have reached the final node, first judge whether it is an duplication
                bool overlap = FALSE;
                STEP *ptr_over = CP->path;
                PATHSET *ptr_over_set = P;
                while (ptr_over_set && ptr_over_set->current && overlap == FALSE)
                {
                    int ptr_len = ptr_over_set->current->length;
                    if (CP->length != ptr_len)
                    {
                        // if the length is different, not duplication
                        ptr_over_set = ptr_over_set->next;
                        continue;
                    }
                    STEP *ptr_over_path = ptr_over_set->current->path;
                    bool is_overlap = TRUE;
                    while (ptr_over || ptr_over_path)
                    {
                        if (ptr_over == NULL || ptr_over_path == NULL)
                        {
                            if (ptr_over == NULL && ptr_over_path == NULL)
                            {
                                // if the number of steps is different, not duplication
                                break;
                            }
                            else
                            {
                                is_overlap = FALSE;
                                break;
                            }
                        }
                        if (ptr_over->point != ptr_over_path->point)
                        {
                            // if we have different node passed, not duplication
                            is_overlap = FALSE;
                            break;
                        }
                        ptr_over = ptr_over->next;
                        ptr_over_path = ptr_over_path->next;
                    }
                    overlap = (is_overlap == FALSE) ? overlap : is_overlap;
                    ptr_over = CP->path;
                    ptr_over_set = ptr_over_set->next;
                }
                if (overlap == TRUE)
                {
                    // duplication happened, back to original state and continue
                    cp_tail->next = NULL;
                    CP->length -= D[start][i].length;
                    continue;
                }
                PATHSET *new = (PATHSET *)malloc(sizeof(struct PathSet)); // allocate space
                new->current = (PATH *)malloc(sizeof(struct Path));       // allocate space
                new->current->length = CP->length;
                new->current->path = NULL;
                STEP *ptr_new = CP->path, *ptr_new_path = new->current->path;
                while (ptr_new)
                {
                    STEP *new_step = (STEP *)malloc(sizeof(struct Step)); // allocate space
                    new_step->point = ptr_new->point;                     // copy the values
                    new_step->next = NULL;
                    if (ptr_new_path == NULL)
                    {
                        new->current->path = new_step;
                        ptr_new_path = new->current->path;
                    }
                    else
                    {
                        ptr_new_path->next = new_step;
                        ptr_new_path = new_step;
                    }
                    ptr_new = ptr_new->next;
                }
                new->next = NULL;
                if (P->current == NULL)
                {
                    P->current = new->current; // append new path to path set
                }
                else
                {
                    PATHSET *ptr_p = P;
                    while (ptr_p->next)
                    {
                        ptr_p = ptr_p->next;
                    }
                    ptr_p->next = new; // append new path to path set
                }
            }
            search_all(P, D, CP, i, M);       // if we haven't reached the final point, go to deeper layer
            cp_tail->next = NULL;             // go to original state
            CP->length -= D[start][i].length; // go to original state
        }
        else
        {
            continue;
        }
    }
}

/**
 * @description: find the 2-nd shortest path based on Dijkstra matrix
 * @param {*}
 * @return {*}
 */
void dijkstra_second(PATH **D, int M)
{
    int min_len = D[0][M - 1].length;
    PATHSET *P;
    P = (PATHSET *)malloc(sizeof(struct PathSet));    // allocate space for path set
    P->current = (PATH *)malloc(sizeof(struct Path)); // allocate space for the path
    P->current = NULL;
    P->next = NULL;
    PATH *CP = (PATH *)malloc(sizeof(struct Path)); // allocate space for the current path
    CP->length = 0;
    CP->path = (STEP *)malloc(sizeof(struct Step)); // allocate space for steps
    CP->path->point = 0;
    CP->path->next = NULL;
    search_all(P, D, CP, 0, M); // search all valid paths
    search_second(P, 1);        // sort for the 2-nd shortest
}
