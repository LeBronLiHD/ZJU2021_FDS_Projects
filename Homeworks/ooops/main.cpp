/*
 * @Author: your name
 * @Date: 2021-10-02 13:46:30
 * @LastEditTime: 2021-10-02 19:20:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ooops\main.cpp
 */

#include "dostack.h"

int main()
{
    std::stack<char> T;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "N = " << i + 1 << std::endl
                  << "getPermuStack = " << getPermuStack(i + 1, 0) << std::endl
                  << "catalan       = " << catalan(i + 1) << std::endl
                  << std::endl;
    }
    int N;
    std::cout << "Input queue length -> ";
    std::cin >> N;
    std::queue<char> Input;
    std::queue<char> Output = {};
    std::stack<char> Temp = {};
    std::cout << "Input sequence     -> ";
    for (int i = 0; i < N; i++)
    {
        char unit;
        std::cin >> unit;
        Input.push(unit);
    }
    init(N);
    doStack(Input, Temp, Output);
    displayans();
    return 0;
}
