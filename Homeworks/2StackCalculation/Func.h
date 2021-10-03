/*
 * @Author: your name
 * @Date: 2021-10-03 15:08:02
 * @LastEditTime: 2021-10-03 15:18:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \2StackCalculation\Func.h
 */

#include "parameter.h"
#include <iostream>

int calculation(int num_1, int num_2, char op)
{
    switch (op)
    {
    case '+':
        return num_1 + num_2;
        break;
    case '-':
        return num_1 - num_2;
        break;
    case '*':
        return num_1 * num_2;
        break;
    case '/':
        if (num_2 != 0)
        {
            return num_1 / num_2;
        }
        else
        {
            std::cout << "divisor is zero!" << std::endl;
            return 0;
        }
        break;
    default:
        std::cout << "operation illegal!" << std::endl;
        break;
    }
    return 0;
}

void F(std::stack<int> *num, std::stack<char> *op)
{
    if (op->empty() || num->size() < 2)
    {
        std::cout << "op is empty or num has insufficient numbers" << std::endl;
        return;
    }
    int num_1 = num->top();
    num->pop();
    int num_2 = num->top();
    num->pop();
    char oper = op->top();
    op->pop();
    int ans = calculation(num_1, num_2, oper);
    num->push(ans);
}
