/*
 * @Author: your name
 * @Date: 2021-10-29 15:50:57
 * @LastEditTime: 2021-11-10 21:48:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
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
    scanf("%d", &M);
    scanf("%d", &N);
    POLYGON PolyOne = InitPolygon(M);
    POLYGON PolyTwo = InitPolygon(N);
    if (DEBUG_MODE)
    {
        DisplayPoly(PolyOne);
        DisplayPoly(PolyTwo);
    }
    InitVotingTable(M, N);
    if (DEBUG_MODE)
    {
        DisplayCurrentVotingTable(M, N);
    }
    SEARCH_PATH Path = InitSearchTree(MAX_SIZE);
    SearchBestMatch(PolyOne, PolyTwo, 0, 0, Path);
    OUTPUT_LIST Output = FindBestMatch(M, N);
    DisplayMatch(Output);
    return 0;
}
