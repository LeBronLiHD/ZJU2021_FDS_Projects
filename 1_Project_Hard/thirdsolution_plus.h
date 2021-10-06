/*
 * @Author: LeBronLiHD
 * @Date: 2021-10-03 21:26:33
 * @LastEditTime: 2021-10-06 11:51:05
 * @LastEditors: Please set LastEditors
 * @Description: Find the maximum submatrix, algorithm 2
 * @FilePath: \1_Project_Hard\thirdsolution_plus.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: Find the maximum submatrix, Time = O(N^4)
 * @param {MATRIX *M}
 * @return {*}
 */
void solution_three_plus_true(MATRIX M) // Not using pointers as parameter for protection
{
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0, CurSum = 0, PreFix = 0;
    int *PreFixSum = (int *)malloc(sizeof(int) * SCALE);
    int i = 0;
    for (M.LeftUp.x = 0; M.LeftUp.x < N; M.LeftUp.x++)
    {
        for (M.LeftUp.y = 0; M.LeftUp.y < N; M.LeftUp.y++)
        {
            for (i = 0; i < N; i++)
            {
                PreFixSum[i] = 0;
            }
            for (M.RightDown.x = M.LeftUp.x; M.RightDown.x < N; M.RightDown.x++)
            {
                // when going through each row, use prefixSumX to
                // record the prefixsum of the row.
                // Likewise, use prefixSumY Array to record
                // the prefixSum of the prev row.
                // prefixSum can help us to avoid some double counting
                PreFix = 0;
                for (M.RightDown.y = M.LeftUp.y; M.RightDown.y < N; M.RightDown.y++)
                {
                    PreFix += M.VALUE[M.RightDown.x][M.RightDown.y];
                    if (M.RightDown.x == M.LeftUp.x)
                    {
                        CurSum = PreFix;
                    }
                    else
                    {
                        CurSum = PreFix + PreFixSum[M.RightDown.y];
                    }
                    // update PreFixSum with CurSum
                    PreFixSum[M.RightDown.y] = CurSum;
                    if (CurSum >= MaxSum)
                    {
                        MaxSum = CurSum;
                        copy_points(&MaxSub, &M);
                    }
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution Three(Plus) Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}

/**
 * @description: solution three with repeation of K times
 * @param {MATRIX M}
 * @return {*}
 */
void solution_three_plus(MATRIX M)
{
    int i = 0;
    for (i = 0; i < K; i++)
    {
        solution_three_plus_true(M);
    }
}
