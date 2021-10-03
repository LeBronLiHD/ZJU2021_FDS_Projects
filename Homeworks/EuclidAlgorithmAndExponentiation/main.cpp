#include "header.h"

int main()
{
    int a = 33, b = 27, c = 332;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd(%d, %d) = %d\n", a, c, gcd(a, c));
    int m, n;
    int gcd_1 = extend_gcd(a, b, gcd(a, b), &m, &n);
    printf("\na = %d, b = %d\nx = %d + t%d\ny = %d + t%d\n", a, b, m, a/gcd_1, n, b/gcd_1);
    int m1, n1;
    // int gcd_2 = extend_gcd(c, a, gcd(c, a), &m1, &n1);
    // printf("\na = %d, b = %d\nx = %d + t%d\ny = %d + t%d\n", c, a, m1, c/gcd_2, n1, a/gcd_2);
    return 0;
}
