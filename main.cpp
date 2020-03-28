#include <iostream>
#include "Time.h"

int main()
{
    Time t(5, 0, 0);
    std::cout << t << std::endl;
    t = t + 3602;
    std::cout << t << std::endl;
    t = t - 3602 - 70;
    std::cout << t << std::endl;
    std::cout << t++ << std::endl;
    std::cout << t-- << std::endl;
    std::cout << --t << std::endl;
    std::cout << ++t << std::endl;
    return 0;
}

