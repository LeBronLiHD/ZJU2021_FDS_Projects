/*
 * @Author: your name
 * @Date: 2021-09-30 22:37:30
 * @LastEditTime: 2021-10-03 17:46:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \PopSequence\main.cpp
 */

#include <iostream>
#include <stack>
#include <queue>
#include <string>

bool judgeValidation_new(std::queue<int> S, int M, int N)
{
    int size = S.size();
    std::stack<int> T;
    for (int i = 1; i < N + 1; i++)
    {
        T.push(i);
        if (T.size() > M)
        {
            return false;
        }
        while (T.size() > 0 &&
               S.size() > 0 &&
               T.top() == S.front())
        {
            T.pop();
            S.pop();
        }
    }
    return (T.empty() == true);
}

bool judgeValidation(std::queue<int> S, int M, int N)
{
    int size = S.size();
    int pre = 0;
    int *found = new int[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        found[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (M + i <= 7 &&
            S.front() > M + i)
        {
            return false;
        }
        if (i == 0)
        {
            pre = S.front();
            S.pop();
            found[pre] = 1;
            continue;
        }
        if (S.front() < pre)
        {
            int cur = pre - 1;
            while (cur >= 1 && found[cur] == 1)
            {
                cur--;
            }
            if (S.front() != cur || cur == 0)
            {
                return false;
            }
        }
        found[S.front()] = 1;
        pre = S.front();
        S.pop();
    }
    return true;
}

void display(std::stack<int> S)
{
    int size = S.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << S.top() << " ";
        S.pop();
    }
    std::cout << std::endl;
}

std::queue<int> readStack(int N)
{
    std::queue<int> S;
    for (int i = 0; i < N; i++)
    {
        int unit;
        std::cin >> unit;
        S.push(unit);
    }
    return S;
}

int main()
{
    int M, N, K;
    std::cin >> M >> N >> K;
    std::queue<bool> answer;
    for (int i = 0; i < K; i++)
    {
        std::queue<int> T(readStack(N));
        // display(T);
        answer.push(judgeValidation_new(T, M, N));
    }
    for (int i = 0; i < K; i++)
    {
        std::string ans = (answer.front()) ? "YES" : "NO";
        std::cout << ans << std::endl;
        answer.pop();
    }
    return 0;
}
