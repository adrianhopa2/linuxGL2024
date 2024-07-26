#include <iostream>
#include <cstdint>


uint64_t fibonacciNumber(unsigned int number)
{
    if (number<= 2)
      return 1;
   else
      return fibonacciNumber(number - 1) + fibonacciNumber(number - 2);
}


int main()
{
    std::cout << "Calculation will take about 10 seconds" << std::endl;
    std::cout << fibonacciNumber(45) << std::endl;

    return 0;
}