/*
 * @Author: your name
 * @Date: 2021-12-14 21:15:17
 * @LastEditTime: 2021-12-14 21:53:11
 * @LastEditors: Please set LastEditors
 * @Description: InsertionOrHeapSort
 * @FilePath: \InsertionOrHeapSort\main.c
 */

#include <stdio.h>

enum bool
{
    FALSE,
    TRUE
};
typedef enum bool bool;

void show(int a[], int len)
{
    printf("%d", a[0]);
    for (int i = 1; i < len; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void insertSort(int a[], int b[], int len)
{
    int i;
    bool flag = FALSE;
    for (i = 1; i < len; i++)
    {
        int key = a[i];
        int j;
        for (j = i; j >= 1 && key < a[j - 1]; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = key;
        int ig;
        for (ig = 0; ig < len; ig++)
        {
            if (a[ig] != b[ig])
                break;
        }
        if (ig >= len)
        {
            printf("Insertion Sort\n");
            flag = TRUE;
            break;
        }
    }
    if (flag == FALSE)
    {
        return;
    }
    i++;
    if (i >= len)
    {
        show(a, len);
    }
    else
    {
        int key = a[i];
        int j;
        for (j = i; j >= 1 && key < a[j - 1]; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = key;
        show(a, len);
    }
    return;
}

void adjust(int a[], int len, int index)
{
    int l = index * 2 + 1;
    int r = index * 2 + 2;
    int maxIndex = index;
    if (l < len && a[maxIndex] < a[l])
    {
        maxIndex = l;
    }
    if (r < len && a[maxIndex] < a[r])
    {
        maxIndex = r;
    }
    if (maxIndex != index)
    {
        int temp = a[index];
        a[index] = a[maxIndex];
        a[maxIndex] = temp;
        adjust(a, len, maxIndex);
    }
    return;
}

void heapSort(int a[], int b[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        adjust(a, len, i);
    }
    int len_index = len;
    int i;
    bool flag = FALSE;
    for (i = len - 1; i >= 1; i--)
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        len_index--;
        adjust(a, len_index, 0);
        int j;
        for (j = 0; j < len; j++)
        {
            if (a[j] != b[j])
            {
                break;
            }
        }
        if (j >= len)
        {
            printf("Heap Sort\n");
            flag = TRUE;
            break;
        }
    }
    if (flag == FALSE)
    {
        return;
    }
    i--;
    if (i == 0)
        show(a, len);
    else
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        len_index--;
        adjust(a, len_index, 0);
        show(a, len);
    }
    return;
}

int main()
{
    int N, a[110], b[110], c[110];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &b[i]);
    }
    insertSort(a, b, N);
    heapSort(c, b, N);
    return 0;
}