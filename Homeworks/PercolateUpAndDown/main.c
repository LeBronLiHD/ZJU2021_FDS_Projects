/*
 * @Author: your name
 * @Date: 2021-10-29 09:29:29
 * @LastEditTime: 2021-10-29 10:18:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \PercolateUpAndDown\main.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

/* Your function will be put here */
PriorityQueue Initialize(int n)
{
    PriorityQueue head = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if(head == NULL) 
	    printf("Out of space!!!"); 
    head->Capacity = n;
    head->Elements = (ElementType*)malloc(sizeof(ElementType) * (n + 1));
    if ( head->Elements == NULL ) 
	    printf("Out of space!!!"); 
    head->Size = 0;
    head->Elements[ 0 ] = MinData;
    return head;
}

void PercolateUp( int p, PriorityQueue H )
{
    ElementType value = H->Elements[p];
    int i = 0;
    for (i = p; i >= 2; i = i/2)
    {
        if(H->Elements[i/2] > value)
        {
            ElementType tmp = H->Elements[i];
            H->Elements[i] = H->Elements[i/2];
            H->Elements[i/2] = tmp;
        }
    }
}

void PercolateDown( int p, PriorityQueue H )
{
    ElementType value = H->Elements[p];
    int i = 0;
    for (i = p; i <= H->Size/2; i = 2 * i)
    {
        if(H->Elements[2 * i] < value)
        {
            ElementType tmp = H->Elements[i];
            H->Elements[i] = H->Elements[2 * i];
            H->Elements[2 * i] = tmp;
        }
    }
}
