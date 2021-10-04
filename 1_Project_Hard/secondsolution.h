/*
 * @Author: your name
 * @Date: 2021-10-03 21:26:33
 * @LastEditTime: 2021-10-04 09:35:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\secondsolution.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: 
 * @param {MATRIX} *M
 * @return {*}
 */
void solution_two(MATRIX M)
{
    int **copy = (int **)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        copy[i] = (int *)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copy[i][j] = M.VALUE[i][j];
        }
    }
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0, CurSum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                M.VALUE[i][j] += M.VALUE[i][j - 1];
            }
            else if (j == 0)
            {
                M.VALUE[i][j] += M.VALUE[i - 1][j];
            }
            else
            {
                M.VALUE[i][j] += M.VALUE[i - 1][j] + M.VALUE[i][j - 1];
                M.VALUE[i][j] -= M.VALUE[i - 1][j - 1];
            }
        }
    }
    for (M.LeftUp.x = 0; M.LeftUp.x < N; M.LeftUp.x++)
    {
        for (M.LeftUp.y = 0; M.LeftUp.y < N; M.LeftUp.y++)
        {
            for (M.RightDown.x = M.LeftUp.x; M.RightDown.x < N; M.RightDown.x++)
            {
                for (M.RightDown.y = M.LeftUp.y; M.RightDown.y < N; M.RightDown.y++)
                {
                    if (M.LeftUp.x == 0 && M.LeftUp.y == 0)
                    {
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y];
                    }
                    else if (M.LeftUp.x == 0)
                    {
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y] -
                                 M.VALUE[M.RightDown.x][M.LeftUp.y - 1];
                    }
                    else if (M.LeftUp.y == 0)
                    {
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y] -
                                 M.VALUE[M.LeftUp.x - 1][M.RightDown.y];
                    }
                    else
                    {
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y] -
                                 M.VALUE[M.LeftUp.x - 1][M.RightDown.y] -
                                 M.VALUE[M.RightDown.x][M.LeftUp.y - 1] +
                                 M.VALUE[M.LeftUp.x - 1][M.LeftUp.y - 1];
                    }
                    if (CurSum >= MaxSum)
                    {
                        copy_points(&MaxSub, &M);
                        MaxSum = CurSum;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            M.VALUE[i][j] = copy[i][j];
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution Two Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}
