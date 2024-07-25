#include <iostream>


template<unsigned int N>
struct fibonacci
{
    static constexpr int64_t value =
        fibonacci<N - 2>::value +
        fibonacci<N - 1>::value;
};

template<>
struct fibonacci<0>
{
    static constexpr int64_t value = 0;
};

template<>
struct fibonacci<1>
{
    static constexpr int64_t value = 1;
};


int main()
{

    constexpr auto fib = fibonacci<92>::value;

    std::cout << fib << std::endl;

    return 0;
}