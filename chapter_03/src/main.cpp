#include <iostream>
#include <cstdint>

class CustomIntAllocator
{
public:
    CustomIntAllocator()
    {
        std::cout << "Default constructor " << std::endl;
    }

    CustomIntAllocator(int *newValue) : value(newValue)
    {
        std::cout << "Storing value " << *value << std::endl;
    }

    CustomIntAllocator(const CustomIntAllocator &other) : value(other.value)
    {
        std::cout << "Copying value " << std::endl;
    }

    CustomIntAllocator &operator=(const CustomIntAllocator &other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        std::cout << "Operator copying value " << std::endl;
        return *this;
    }

    CustomIntAllocator(CustomIntAllocator &&other) noexcept : value(other.value)
    {
        other.value = nullptr;
        std::cout << "Moving value " << std::endl;
    }

    CustomIntAllocator &operator=(CustomIntAllocator &&other)
    {
        if (this != &other)
        {
            value = other.value;
            other.value = nullptr;
        }
        std::cout << "Operator moving value " << std::endl;
        return *this;
    }

    ~CustomIntAllocator()
    {
        std::cout << "Freeing value ";
        if (value != nullptr)
        {
            std::cout << *value << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }
    }

private:
    int *value{nullptr};
};

int main()
{

    CustomIntAllocator pointer1{new int(42)};

    CustomIntAllocator pointer2{pointer1};

    CustomIntAllocator pointer3;
    pointer3 = pointer2;

    CustomIntAllocator pointer4 = std::move(pointer1);

    CustomIntAllocator pointer5;
    pointer5 = std::move(pointer2);

    std::cout << "end of main()" << std::endl;

    return 0;
}