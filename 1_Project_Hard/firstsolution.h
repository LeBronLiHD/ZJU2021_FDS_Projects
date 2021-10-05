/*
 * @Author: LeBronLiHD
 * @Date: 2021-09-25 23:50:51
 * @LastEditTime: 2021-10-05 13:37:45
 * @LastEditors: Please set LastEditors
 * @Description: Find the maximum submatrix, algorithm 1
 * @FilePath: \1_Project_Hard\firstsolution.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: Find the maximum submatrix, Time = O(N^6)
 * @param {MATRIX M}
 * @return {*}
 */
void solution_one(MATRIX M) // Not using pointers as parameter for protection
{
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0, CurSum = 0;
    for (M.LeftUp.x = 0; M.LeftUp.x < N; M.LeftUp.x++)
    {
        for (M.LeftUp.y = 0; M.LeftUp.y < N; M.LeftUp.y++)
        {
            for (M.RightDown.x = M.LeftUp.x; M.RightDown.x < N; M.RightDown.x++)
            {
                for (M.RightDown.y = M.LeftUp.y; M.RightDown.y < N; M.RightDown.y++)
                {
                    // four layers of 'for' loop, polling every possible submatrix
                    CurSum = calculate_sum(&M);
                    // calculate the sum of current submatrix, O(N^2)
                    if (CurSum >= MaxSum)
                    {
                        copy_points(&MaxSub, &M);   // update the range of submatrix
                        MaxSum = CurSum;            // update maximum sum
                    }
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);    // update the range of submatrix in MATRIX M
    printf("\nCalculation of Solution One Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}
