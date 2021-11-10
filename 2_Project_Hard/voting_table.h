/*
 * @Author: your name
 * @Date: 2021-11-10 15:37:33
 * @LastEditTime: 2021-11-10 22:15:39
 * @LastEditors: Please set LastEditors
 * @Description: APIs of voting table
 * @FilePath: \2_Project_Hard\voting_table.h
 */

#pragma once

#include "data_structure.h"

/**
 * @description: Display Current Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void DisplayCurrentVotingTable(const int M, const int N)
{
    printf("Current Voting Table ->\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", VOTING_TABLE[i][j]);
        }
        printf("\n");
    }
    return;
}

/**
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void InitVotingTable(const int M, const int N)
{
    // allocate memory space
    VOTING_TABLE = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
        // allocate memory space
        VOTING_TABLE[i] = (int *)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            VOTING_TABLE[i][j] = 0;
        }
    }
    return;
}

/**
 * @description: find the best match through the voting table
 * @param int SizeOne, int SizeTwo
 * @return OUTPUT_LIST
 */
OUTPUT_LIST FindBestMatch(int SizeOne, int SizeTwo)
{
    // allocate memory space
    OUTPUT_LIST OutputHead = (OUTPUT_LIST)malloc(sizeof(struct OutputList));
    OUTPUT_LIST OutputTail = OutputHead;
    OutputHead->next_output = NULL;
    // allocate memory space
    // use as a flag to judge whether the points of second polygon is processed
    int *is_matched = (int *)malloc(sizeof(int) * SizeTwo);
    for (int i = 0; i < SizeTwo; i++)
    {
        // initialize the flag
        is_matched[i] = 0;
    }
    for (int i = 0; i < SizeOne; i++)
    {
        int MaxIndex = 0;
        for (int j = 0; j < SizeTwo; j++)
        {
            // find the biggest vote in row i
            if (VOTING_TABLE[i][j] > VOTING_TABLE[i][MaxIndex])
            {
                MaxIndex = j;
            }
        }
        if (VOTING_TABLE[i][MaxIndex] != 0)
        {
            if (is_matched[MaxIndex])
            {
                continue;
            }
            // allocate memory space
            OUTPUT_LIST CurNode = (OUTPUT_LIST)malloc(sizeof(struct OutputList));
            // if the biggest in row i is not aero and the point has not been counted
            // then put the point to the final output and marked its flag
            CurNode->index_one = i + 1;
            CurNode->index_two = MaxIndex + 1;
            CurNode->next_output = NULL;
            OutputTail->next_output = CurNode;
            OutputTail = CurNode;
            is_matched[MaxIndex] = 1;
        }
    }
    return OutputHead;
}

/**
 * @description: print the answer
 * @param OUTPUT_LIST Output
 * @return {*}
 */
void DisplayMatch(OUTPUT_LIST Output)
{
    Output = Output->next_output;
    if(Output == NULL)
    {
        // if the output is NULL, print the error massage
        printf("Error! Empty Output! file:voting_table.h line:119 function:DisplayMatch()\n");
        return;
    }
    printf("\n");
    while (Output != NULL)
    {
        // print the points of the output
        printf("(%d, %d)\n", Output->index_one, Output->index_two);
        Output = Output->next_output;
    }
    return;
}
