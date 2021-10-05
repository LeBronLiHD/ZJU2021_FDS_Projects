/*
 * @Author: LeBronLiHD
 * @Date: 2021-10-03 21:26:33
 * @LastEditTime: 2021-10-05 19:34:46
 * @LastEditors: Please set LastEditors
 * @Description: Find the maximum submatrix, algorithm 2
 * @FilePath: \1_Project_Hard\thirdsolution.h
 */

#pragma once

#include "interfaces.h"

/**
 * @description: Find the maximum submatrix, Time = O(N^4)
 * @param {MATRIX *M}
 * @return {*}
 */
void solution_three_true(MATRIX M) // Not using pointers as parameter for protection
{
    int **copy = (int **)malloc(sizeof(int) * SCALE); // allocate memory space
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        copy[i] = (int *)malloc(sizeof(int) * SCALE);
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            copy[i][j] = M.VALUE[i][j];
        }
    }
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0, CurSum = 0;
    // first, we modify the original matrix, in order to satisfy
    // sum_of_submatrix = M[Right][Down] - M[Left][Down] - M[Right][Up] + M[Left][Up]
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                // LeftUp POINT is at the top left corner of the matrix
                continue;
            }
            else if (i == 0)
            {
                // LeftUp POINT is at the top row of the matrix
                M.VALUE[i][j] += M.VALUE[i][j - 1];
            }
            else if (j == 0)
            {
                // LeftUp POINT is at the left column of the matrix
                M.VALUE[i][j] += M.VALUE[i - 1][j];
            }
            else
            {
                M.VALUE[i][j] += M.VALUE[i - 1][j] + M.VALUE[i][j - 1];
                M.VALUE[i][j] -= M.VALUE[i - 1][j - 1];
            }
        }
    }
    // second, poll every possible submatrix and find the biggest
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
                        // LeftUp POINT is at the top left corner of the matrix
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y];
                    }
                    else if (M.LeftUp.x == 0)
                    {
                        // LeftUp POINT is at the top row of the matrix
                        CurSum = M.VALUE[M.RightDown.x][M.RightDown.y] -
                                 M.VALUE[M.RightDown.x][M.LeftUp.y - 1];
                    }
                    else if (M.LeftUp.y == 0)
                    {
                        // LeftUp POINT is at the left column of the matrix
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
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            M.VALUE[i][j] = copy[i][j];
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation of Solution Three Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n",
           M.LeftUp.x + 1, M.LeftUp.y + 1, M.RightDown.x + 1, M.RightDown.y + 1);
    printf("Max Sum \t-> %d\n", MaxSum);
}

/**
 * @description: solution three with repeation of K times
 * @param {MATRIX M}
 * @return {*}
 */
void solution_three(MATRIX M)
{
    int i = 0;
    for (i = 0; i < K; i++)
    {
        solution_three_true(M);
    }
}
