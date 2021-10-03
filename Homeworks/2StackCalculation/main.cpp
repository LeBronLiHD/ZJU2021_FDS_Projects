/*
 * @Author: your name
 * @Date: 2021-10-03 15:07:34
 * @LastEditTime: 2021-10-03 15:27:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \2StackCalculation\main.cpp
 */

#include "Func.h"

int main()
{
    std::cout << "Input calculate times -> ";
    int N;
    std::cin >> N;
    init();
    for (int i = 0; i < N; i++)
    {
        F(&numbers, &operations);
        std::cout << std::endl
                  << "Time: " << i + 1 << std::endl
                  << "Num.top = " << numbers.top() << std::endl;
    }
    return 0;
}
