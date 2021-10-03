#include <iostream>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int gcd(int a, int b)
{
    if (max(a, b) % min(a, b) == 0)
    {
        return min(a, b);
    }
    else
    {
        return gcd(min(a, b), max(a, b) - (max(a, b) / min(a, b)) * min(a, b));
    }
}

int recursion_gcd(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *y = 0;
        *x = 1;
        return b;
    }
    int _x, _y;
    int gcd = recursion_gcd(b, a % b, &_x, &_y);
    *x = _y - (b / a) * _x;
    *y = _x;
    return gcd;
}

int extend_gcd(int a, int b, int c, int *m, int *n)
{
    if (c % gcd(a, b) != 0)
    {
        printf("c % gcd(a, b) != 0");
        return 0;
    }
    int K = c / gcd(a, b);
    int _m, _n;
    int gcd = recursion_gcd(a, b, &_m, &_n);
    *m = _m * K;
    *n = _n * K;
    return gcd;
}
