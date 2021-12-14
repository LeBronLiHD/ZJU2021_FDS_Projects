/*
 * @Author: your name
 * @Date: 2021-12-14 21:03:46
 * @LastEditTime: 2021-12-14 21:11:17
 * @LastEditors: Please set LastEditors
 * @Description: Iterative Mergesort
 * @FilePath: \IterativeMergesort\main.c
 */

#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass(ElementType list[], ElementType sorted[], int N, int length);

void output(ElementType list[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void merge_sort(ElementType list[], int N)
{
    ElementType extra[MAXN]; /* the extra space required */
    int length = 1;          /* current length of sublist being merged */
    while (length < N)
    {
        merge_pass(list, extra, N, length); /* merge list into extra */
        output(extra, N);
        length *= 2;
        merge_pass(extra, list, N, length); /* merge extra back to list */
        output(list, N);
        length *= 2;
    }
}

int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */

void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
    for (int i = 0; i < N; i = i + 2 * length)
    {
        int index_1 = i;
        int index_2 = i + length;
        int index = i;
        int last = (i + 2 * length > N) ? N : i + 2 * length;
        while (index_1 < i + length && index_2 < last &&
               index_1 < N && index_2 < N &&
               index_1 >= 0 && index_2 >= 0)
        {
            if (list[index_1] < list[index_2])
            {
                sorted[index++] = list[index_1++];
            }
            else
            {
                sorted[index++] = list[index_2++];
            }
        }
        while (index_1 < i + length)
        {
            sorted[index++] = list[index_1++];
        }
        while (index_2 < last)
        {
            sorted[index++] = list[index_2++];
        }
    }
}
