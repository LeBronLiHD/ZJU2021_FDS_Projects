/*
 * @Author: your name
 * @Date: 2021-10-16 11:52:24
 * @LastEditTime: 2021-10-17 22:37:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Isomorphic\main.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};

Tree BuildTree(); /* details omitted */

void show(Tree bt, int level);

int Isomorphic(Tree T1, Tree T2);

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    printf("-----------------------------------------------------------\n");
    T2 = BuildTree();
    show(T1, 0);
    printf("-----------------------------------------------------------\n");
    show(T2, 0);
    printf("%d\n", Isomorphic(T1, T2));
    return 0;
}

Tree BuildTree()
{
    char init;
    int leftOrRight;
    printf("input element -> ");
    scanf("\n%c", &init);
    Tree head = (Tree)malloc(sizeof(struct TreeNode));
    head->Element = init;
    head->Left = NULL;
    head->Right = NULL;
    printf("go left or right or both -> ");
    scanf("%d", &leftOrRight);
    switch (leftOrRight)
    {
    case 0:
        printf("left child!\n");
        head->Left = BuildTree();
        break;
    case 1:
        printf("right child!\n");
        head->Right = BuildTree();
        break;
    case 2:
        printf("left child!\n");
        head->Left = BuildTree();
        printf("right child!\n");
        head->Right = BuildTree();
        break;
    default:
        break;
    }
    return head;
}

void show(Tree bt, int level)
{
    if (!bt)
        return;
    show(bt->Left, level + 1);
    for (int i = 0; i < level; i++)
        printf("      ");
    printf("%c\n\n", bt->Element);
    show(bt->Right, level + 1);
}

/* Your function will be put here */
int Isomorphic(Tree T1, Tree T2)
{
    if (T1 == NULL && T2 == NULL)
    {
        return 1;
    }
    else
    {
        if (!(T1 && T2))
        {
            return 0;
        }
        else if(T1->Element != T2->Element)
        {
            return 0;
        }
    }
    if (T1->Left == NULL &&
        T1->Right == NULL &&
        T2->Left == NULL &&
        T2->Right == NULL &&
        T1->Element == T2->Element)
    {
        return 1;
    }
    else if (T1->Left == NULL &&
             T2->Left == NULL &&
             T2->Right &&
             T1->Right &&
             T1->Right->Element == T2->Right->Element)
    {
        return Isomorphic(T1->Right, T2->Right);
    }
    else if (T1->Left &&
             T2->Left &&
             T2->Right == NULL &&
             T1->Right == NULL &&
             T1->Left->Element == T2->Left->Element)
    {
        return Isomorphic(T1->Left, T2->Left);
    }
    else if (T1->Left == NULL &&
             T2->Right == NULL &&
             T2->Left &&
             T1->Right &&
             T1->Right->Element == T2->Left->Element)
    {
        return Isomorphic(T1->Right, T2->Left);
    }
    else if (T1->Left &&
             T2->Right &&
             T2->Left == NULL &&
             T1->Right == NULL &&
             T1->Left->Element == T2->Right->Element)
    {
        return Isomorphic(T1->Left, T2->Right);
    }
    if (T1->Left && T2->Left && T1->Right && T2->Right && T1->Element == T2->Element &&
        T1->Left->Element == T2->Left->Element &&
        T1->Right->Element == T2->Right->Element)
    {
        return Isomorphic(T1->Left, T2->Left) * Isomorphic(T1->Right, T2->Right);
    }
    else if (T1->Left && T2->Left && T1->Right && T2->Right && T1->Element == T2->Element &&
             T1->Left->Element == T2->Right->Element &&
             T1->Right->Element == T2->Left->Element)
    {
        return Isomorphic(T1->Left, T2->Right) * Isomorphic(T1->Right, T2->Left);
    }
    else
    {
        return 0;
    }
}

/*
A
2
B
2
D
9
E
0
F
9
C
0
G
0
H
9
A
2
B
0
G
1
H
9
C
2
D
0
F
9
E
9

*/
