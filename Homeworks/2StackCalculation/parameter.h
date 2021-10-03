/*
 * @Author: your name
 * @Date: 2021-10-03 15:07:54
 * @LastEditTime: 2021-10-03 15:27:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \2StackCalculation\parameter.h
 */

#include <stack>

std::stack<int> numbers;
std::stack<char> operations;

void init()
{
    numbers.push(5);
    numbers.push(8);
    numbers.push(3);
    numbers.push(2);
    operations.push('*');
    operations.push('-');
    operations.push('+');
}
