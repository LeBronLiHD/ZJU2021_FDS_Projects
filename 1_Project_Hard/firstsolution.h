/*
 * @Author: your name
 * @Date: 2021-09-25 23:50:51
 * @LastEditTime: 2021-10-04 00:19:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\firstsolution.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void solution_one(MATRIX M)
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
                    CurSum = calculate_sum(&M);
                    if (CurSum >= MaxSum)
                    {
                        copy_points(&MaxSub, &M);
                        MaxSum = CurSum;
                    }
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution One Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}
