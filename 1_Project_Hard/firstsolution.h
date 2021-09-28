/*
 * @Author: your name
 * @Date: 2021-09-25 23:50:51
 * @LastEditTime: 2021-09-26 13:35:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \1_Project_Hard\firstsolution.h
 */

#include "interfaces.h"

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
void SolutionOne(MATRIX M)
{
    SUBMAT MaxSub = {{0, 0}, {0, 0}};
    int MaxSum = 0;
    for (M.LeftUp.x = 0; M.LeftUp.x < N; M.LeftUp.x++)
    {
        for (M.LeftUp.y = 0; M.LeftUp.y < N; M.LeftUp.y++)
        {
            for (M.RightDown.x = M.LeftUp.x; M.RightDown.x < N; M.RightDown.x++)
            {
                for (M.RightDown.y = M.LeftUp.y; M.RightDown.y < N; M.RightDown.y++)
                {
                    if(calculate_sum(M) >= MaxSum)
                    {
                        copy_points(&MaxSub, &M);
                        MaxSum = calculate_sum(M);
                    }
                }
            }
        }
    }
    copy_submatrix(&MaxSub, &M);
    printf("\nCalculation Done!\nSub Matrix \t-> from (%d, %d) to (%d, %d)\n", M.LeftUp.x, M.LeftUp.y, M.RightDown.x, M.RightDown.y);
    printf("Max Sum \t-> %d\n", calculate_sum(M));
}
