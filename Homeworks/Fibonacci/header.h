#include <iostream>

class Fibonacci
{
private:
    int num;
    int time;

public:
    Fibonacci(int n);
    ~Fibonacci(){};
    int CalculateOne();
    int CalculateTwo() { return recursion(num); }
    int recursion(int n);
    int getTime() { return time; }
    int Factorial() { return Factorial_re(num); }
    int Factorial_re(int num);
};

Fibonacci::Fibonacci(int n) : num(n), time(0) {}

int Fibonacci::CalculateOne()
{
    int a = 1, b = 1;
    for (int i = 0; i < num - 2; i++)
    {
        a += b;
        b = a - b;
    }
    return a;
}

int Fibonacci::recursion(int n)
{
    if (n == 1 || n == 2)
    {
        time++;
        return 1;
    }
    time++;
    int one = recursion(n - 1);
    int two = recursion(n - 2);
    // std::cout << "recursion(" << n << " - 1) = " << one << std::endl;
    // std::cout << "recursion(" << n << " - 2) = " << two << std::endl;
    return one + two;
}

int Fibonacci::Factorial_re(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    return num * Factorial_re(num - 1);
}
