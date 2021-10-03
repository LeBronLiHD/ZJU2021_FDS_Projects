/*
 * @Author: your name
 * @Date: 2021-10-02 13:55:59
 * @LastEditTime: 2021-10-02 16:05:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ooops\header.h
 */

#include <stack>
#include <vector>
#include <iostream>

long long getPermuStack(int n, int m)
{
    if (n == 0) //递归边界
        return 1;
    if (m == 0) //(n,0)问题的处理
        return getPermuStack(n - 1, 1);
    return getPermuStack(n, m - 1) + getPermuStack(n - 1, m + 1);
}

//Catalan公式法 最多只能算到n=10
long long jiecheng(long long n)
{
    if (n == 1)
        return 1;
    else
        return n * jiecheng(n - 1);
}

long long catalan(long long n)
{
    return (jiecheng(2 * n) / jiecheng(n + 1) / jiecheng(n));
}
