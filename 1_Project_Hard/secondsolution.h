/*
 * @Author: LeBronLiHD
 * @Date: 2021-10-03 23:16:52
 * @LastEditTime: 2021-10-05 18:59:45
 * @LastEditors: Please set LastEditors
 * @Description: Find the maximum submatrix, algorithm 3
 * @FilePath: \1_Project_Hard\secondsolution.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: Find the maximum submatrix, Time = O(N^3)
 * @param {MATRIX M}
 * @return {*}
 */
void solution_two_true(MATRIX M) // Not using pointers as parameter for protection
{
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int AllMinus = max_element(&M) < 0;
    int MaxSum = 0, CurSum = 0;
    int *MaxCol = malloc(sizeof(int) * N); // allocate memory space
    int left = 0, i = 0, right = 0;
    for (left = 0; left < N && AllMinus != 1; left++)
    {
        for (i = 0; i < N; i++)
        {
            // re-initialize the MaxCol once the left column changed
            MaxCol[i] = 0;
        }
        for (right = left; right < N; right++)
        {
            for (i = 0; i < N; i++)
            {
                // let MaxCol be the accumulation sum of columns
                MaxCol[i] += M.VALUE[i][right];
            }
            int up = 0, down = 0;
            CurSum = 0;
            // use dynamic programming to find the maximum subarray of MaxCol
            for (i = 0; i < N; i++)
            {
                CurSum += MaxCol[i];
                down = i;
                if (CurSum > MaxSum)
                {
                    // update MaxSum and the submatrix range MaxSub
                    MaxSum = CurSum;
                    update_submatrix_value(&MaxSub, up, left, down, right);
                }
                if (CurSum <= 0)
                {
                    // re-initialize CurSum and up
                    CurSum = 0;
                    up = i + 1;
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution two Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}

/**
 * @description: solution two with repeation of K times
 * @param {MATRIX M}
 * @return {*}
 */
void solution_two(MATRIX M)
{
    int i = 0;
    for ( i = 0; i < K; i++)
    {
        solution_two_true(M);
    }
    
}
