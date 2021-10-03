/*
 * @Author: your name
 * @Date: 2021-10-02 14:11:15
 * @LastEditTime: 2021-10-02 19:21:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ooops\dostack.h
 */

#include "header.h"
#include <queue>

static int count = 0;
static int countSame = 0;
static std::queue<char> comQueue;

void displayans()
{
    std::cout << std::endl
              << "Calculation done! FinalCount = " << countSame << std::endl;
}

void init(int N)
{
    std::cout << "Compare sequence   -> ";
    for (int i = 0; i < N; i++)
    {
        char unit;
        std::cin >> unit;
        comQueue.push(unit);
    }
}

bool compare(std::queue<char> out, std::queue<char> comQ)
{
    int size = out.size();
    for (int i = 0; i < size; i++)
    {
        if (out.front() == comQ.front())
        {
            out.pop();
            comQ.pop();
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void display(int cnt, std::queue<char> out)
{
    int size = out.size();
    bool isSame = compare(out, comQueue);
    std::cout << "count = " << cnt << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << out.front() << " ";
        out.pop();
    }
    if (isSame)
    {
        countSame++;
        std::cout << "   Wow!!!!!  CountSame = " << countSame;
    }
    std::cout << std::endl;
}

void doStack(std::queue<char> in, std::stack<char> s, std::queue<char> out)
{
    if (in.empty())
    {
        if (s.empty())
        {
            count++;
            display(count, out);
        }
        else
        {
            out.push(s.top());
            s.pop();
            doStack(in, s, out);
        }
    }
    else
    {
        if (!s.empty())
        {
            std::stack<char> ts;
            std::queue<char> tin, tout;
            tin = in;
            ts = s;
            tout = out;
            tout.push(ts.top());
            ts.pop();
            doStack(tin, ts, tout);
        }
        s.push(in.front());
        in.pop();
        doStack(in, s, out);
    }
}
