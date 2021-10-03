/*
 * @Author: your name
 * @Date: 2021-10-03 17:52:23
 * @LastEditTime: 2021-10-03 19:40:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Bonus-1_OneWayIn_TwoWaysOut\main.cpp
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::queue<int> readQueue(int N)
{
    std::queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        int unit;
        std::cin >> unit;
        Q.push(unit);
    }
    return Q;
}

void deleteBack(std::queue<int> *S)
{
    if (S->size() == 1)
    {
        S->pop();
        return;
    }
    std::queue<int> T;
    while (S->size() > 1)
    {
        T.push(S->front());
        S->pop();
    }
    S->pop();
    while (T.empty() == false)
    {
        S->push(T.front());
        T.pop();
    }
}

bool judgeValidation(std::queue<int> Insert, int N)
{
    std::queue<int> Q = readQueue(N);
    std::queue<int> S;
    for (int i = 0; i < N; i++)
    {
        S.push(Insert.front());
        Insert.pop();
        while (Q.size() > 0 &&
               S.size() > 0 &&
               (Q.front() == S.back() || Q.front() == S.front()))
        {
            if (Q.front() == S.front())
            {
                Q.pop();
                S.pop();
                continue;
            }
            if (Q.front() == S.back())
            {
                Q.pop();
                deleteBack(&S);
            }
        }
    }
    return S.empty();
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    std::queue<int> Insert;
    for (int i = 0; i < N; i++)
    {
        int unit;
        std::cin >> unit;
        Insert.push(unit);
    }
    std::vector<std::string> answer;
    for (int i = 0; i < K; i++)
    {
        std::string ans = (judgeValidation(Insert, N)) ? "yes" : "no";
        answer.push_back(ans);
    }
    for (int i = 0; i < K; i++)
    {
        std::cout << answer.at(i) << std::endl;
    }
    return 0;
}
