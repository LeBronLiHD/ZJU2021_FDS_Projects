/*
 * @Author: your name
 * @Date: 2021-11-10 15:37:33
 * @LastEditTime: 2021-11-10 20:30:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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
    printf("Current Voting Table ->");
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
    VOTING_TABLE = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
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
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
OUTPUT_LIST FindBestMatch(int SizeOne, int SizeTwo)
{
    OUTPUT_LIST OutputHead = (OUTPUT_LIST)malloc(sizeof(struct OutputList));
    OUTPUT_LIST OutputTail = OutputHead;
    int *is_matched = (int *)malloc(sizeof(int) * SizeTwo);
    for (int i = 0; i < SizeTwo; i++)
    {
        is_matched[i] = 0;
    }
    for (int i = 0; i < SizeOne; i++)
    {
        int MaxIndex = 0;
        for (int j = 0; j < SizeTwo; j++)
        {
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
            OUTPUT_LIST CurNode = (OUTPUT_LIST)malloc(sizeof(struct OutputList));
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
 * @description: Init Voting Table
 * @param const int M, const int N
 * @return {*}
 */
void DisplayMatch(OUTPUT_LIST Output)
{
    Output = Output->next_output;
    printf("\nMatch:\n");
    while (Output != NULL)
    {
        printf("(%d, %d)\n", Output->index_one, Output->index_two);
        Output = Output->next_output;
    }
    return;
}
