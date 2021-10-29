/*
 * @Author: your name
 * @Date: 2021-10-29 15:01:06
 * @LastEditTime: 2021-10-29 15:10:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CompleteBinarySearchTree_10\csdn.c
 */

#include <stdio.h>

#define MAX 1010

int SIZE;
int INPUT[MAX];
int CBT[MAX];
int INDEX;

void Transfer(int root)
{
    if (root > SIZE)
        return;
    inOrder(root * 2);
    CBT[root] = INPUT[INDEX++];
    inOrder(root * 2 + 1);
}

int main()
{
    scanf("%d", &SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        int unit;
        scanf("%d", &unit);
        if (i == 0)
        {
            INPUT[i] = unit;
            continue;
        }
        int isfill = 0;
        for (int j = 0; j < i; j++)
        {
            if (INPUT[j] > unit)
            {
                for (int r = i - 1; r > j; r++)
                {
                    INPUT[r] = INPUT[r - 1];
                }
                INPUT[j] = unit;
                isfill = 1;
                break;
            }
        }
        if (isfill == 0)
            INPUT[i] = unit;
    }
    Transfer(1);
    for (int i = 1; i <= SIZE - 1; i++)
        printf("%d ", CBT[i]);
    printf("%d", CBT[SIZE]);
}
