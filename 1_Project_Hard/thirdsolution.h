/*
 * @Author: your name
 * @Date: 2021-10-03 23:16:52
 * @LastEditTime: 2021-10-04 09:42:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\solutionthree.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void solution_three(MATRIX M)
{
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0, CurSum = 0;
    int *MaxCol = (int *)malloc(sizeof(int) * N);
    for (int left = 0; left < N; left++)
    {
        for (int i = 0; i < N; i++)
        {
            MaxCol[i] = 0;
        }
        for (int right = left; right < N; right++)
        {
            for (int i = 0; i < N; i++)
            {
                MaxCol[i] += M.VALUE[i][right];
            }
            int up = 0, down = 0;
            CurSum = 0;
            for (int i = 0; i < N; i++)
            {
                CurSum += MaxCol[i];
                down = i;
                if (CurSum > MaxSum)
                {
                    MaxSum = CurSum;
                    update_submatrix_value(&MaxSub, up, left, down, right);
                }
                if (CurSum <= 0)
                {
                    CurSum = 0;
                    up = i + 1;
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution Three Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}
