/*
 * @Author: LeBronLiHD
 * @Date: 2021-09-25 19:55:01
 * @LastEditTime: 2021-10-05 21:52:48
 * @LastEditors: Please set LastEditors
 * @Description: The main() function of the project
 * @FilePath: \1_Project_Hard\main.c
 */

#include "firstsolution.h"
#include "secondsolution.h"
#include "thirdsolution.h"

/**
 * @description: main() function of the entire project 
 * @param {*}
 * @return {*}
 */
int main()
{
    MATRIX M;           // Definition the matrix to be dealt with
    init_matrix(&M);    // Initialize the basic infomation(rows, columns, etc.) of M
                        // also initialize the value of N and IS_MANUAL_OR_AUTO
    read_matrix(&M);    // Initializes the values of each element of the matrix
    print_matrix(&M);   // Display the values of each element of the matrix 
    get_cur_time();     // Get first current time and document it
    solution_one(M);    // Find the maximum submatrix by solution one, O(N^6)
    get_cur_time();     // Get second current time and document it, 
                        // we can calculate the time spent in solution one
    solution_two(M);    // Find the maximum submatrix by solution two, O(N^4)
    get_cur_time();     // Get third current time and document it, 
                        // we can calculate the time spent in solution two
    solution_three(M);  // Find the maximum submatrix by solution three, O(N^3)
    get_cur_time();     // Get fourth current time and document it, 
                        // we can calculate the time spent in solution three
    display_time();     // Calculate the time spent in each solution, and display them
    return 0;
}
