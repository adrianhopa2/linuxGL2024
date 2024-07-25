#include <iostream>


int64_t fibonacciNumber(unsigned int number)
{
    int64_t temp0 = 0;
    int64_t temp1 = 1;

    for (uint i = 0; i < number; i++)
    {
        temp1 += temp0;
        temp0 = temp1 - temp0;
    }

    return temp0;
}


int main()
{

    std::cout << fibonacciNumber(92) << std::endl;

    return 0;
}