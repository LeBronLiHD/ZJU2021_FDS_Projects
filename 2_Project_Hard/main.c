/*
 * @Author: your name
 * @Date: 2021-10-29 15:50:57
 * @LastEditTime: 2021-11-10 23:49:14
 * @LastEditors: Please set LastEditors
 * @Description: Main Function of the Whole Project
 * @FilePath: \2_Project_Hard\main.c
 */

#include "data_structure.h"
#include "init_polygon.h"
#include "search_path.h"
#include "voting_table.h"

const static int DEBUG_MODE = 0;
const static int MAX_SIZE = 200;

/**
 * @description: Main Function of the Project
 * @param {*}
 * @return {*}
 */
int main()
{
    int M, N;
    // input the number of points
    scanf("%d", &M);
    scanf("%d", &N);
    // initialize two polygons
    POLYGON PolyOne = InitPolygon(M);
    POLYGON PolyTwo = InitPolygon(N);
    if (DEBUG_MODE)
    {
        // if debug_mode, print the polygons
        DisplayPoly(PolyOne);
        DisplayPoly(PolyTwo);
    }
    // initialize voting table all zeros
    InitVotingTable(M, N);
    if (DEBUG_MODE)
    {
        // if debug_mode, print the current voting table
        DisplayCurrentVotingTable(M, N);
    }
    // initialize the serching tree
    SEARCH_PATH Path = InitSearchTree(MAX_SIZE);
    // use bfs for voting
    SearchBestMatch(PolyOne, PolyTwo, 0, 0, Path);
    // find the best match through the voting table
    OUTPUT_LIST Output = FindBestMatch(M, N);
    // display the answer
    DisplayMatch(Output);
    system("pause");
    return 0;
}
