/*
Fibonacci Time Complexity and Space Complexity
1 1 2 3 5 8 13 ...
LeBronLiHD
*/

#include <iostream>
#include "header.h"

int main()
{
    Fibonacci obj(15);
    std::cout << "Function one   -> " << obj.CalculateOne() << std::endl;
    std::cout << "Function two   -> " << obj.CalculateTwo() << std::endl;
    std::cout << "Time of FunTwo -> " << obj.getTime() << std::endl;
    std::cout << "Factorial      -> " << obj.Factorial() << std::endl;
    return 0;
}
