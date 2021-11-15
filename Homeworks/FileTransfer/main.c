/*
 * @Author: your name
 * @Date: 2021-11-15 15:24:47
 * @LastEditTime: 2021-11-15 19:57:02
 * @LastEditors: Please set LastEditors
 * @Description: File Transfer
 * @FilePath: \FileTransfer\main.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001

typedef int ELEMENT_TYPE;
typedef ELEMENT_TYPE SET[MAX_SIZE];
typedef int SET_NAME;
typedef int SIZE_TYPE;
typedef char INPUT_COMMAND;

void Union(SET S, SET_NAME RootOne, SET_NAME RootTwo)
{
    if (S[RootOne] > S[RootTwo])
    {
        S[RootOne] = RootTwo;
    }
    else if (S[RootOne] < S[RootTwo])
    {
        S[RootTwo] = RootOne;
    }
    else
    {
        ELEMENT_TYPE Root = S[RootOne] - 1;
        S[RootTwo] = RootOne;
        S[RootOne] = Root;
    }
}

SET_NAME Find(SET S, ELEMENT_TYPE X)
{
    for (; S[X] >= 0; X = S[X])
        ;
    return X;
}

void CheckNetwork(SET S, SIZE_TYPE N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] < 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        printf("The network is connected.\n");
    }
    else
    {
        printf("There are %d components.\n", count);
    }
}

void CheckConnection(SET S)
{
    ELEMENT_TYPE One, Two;
    SET_NAME RootOne, RootTwo;
    scanf("%d%d\n", &One, &Two);
    RootOne = Find(S, One - 1);
    RootTwo = Find(S, Two - 1);
    if (RootOne == RootTwo)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

void InputConnection(SET S)
{
    ELEMENT_TYPE One, Two;
    scanf("%d%d\n", &One, &Two);
    SET_NAME RootOne, RootTwo;
    RootOne = Find(S, One - 1);
    RootTwo = Find(S, Two - 1);
    if (RootOne != RootTwo)
    {
        Union(S, RootOne, RootTwo);
    }
}

void Initialization(SET S, SIZE_TYPE N)
{
    for (int i = 0; i < N; i++)
        S[i] = -1;
}

int main()
{
    SIZE_TYPE N;
    INPUT_COMMAND C;
    scanf("%d\n", &N);
    SET S;
    Initialization(S, N);
    while (1)
    {
        scanf("%c", &C);
        switch (C)
        {
        case 'I':
            InputConnection(S);
            break;
        case 'C':
            CheckConnection(S);
            break;
        case 'S':
            CheckNetwork(S, N);
            break;
        default:
            printf("\nERROR!\n");
            break;
        }
        if (C == 'S')
        {
            break;
        }
    }
    return 0;
}
