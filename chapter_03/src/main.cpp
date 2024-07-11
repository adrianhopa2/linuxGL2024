#include <iostream>
#include <memory>


class SmartPointer
{
private:
    int *ptr;

public:
    SmartPointer(int *pointer = nullptr) : ptr{pointer}
    {
        std::cout << "SmartPointer constructor" << std::endl;
    }

    ~SmartPointer()
    {
        std::cout << "SmartPointer destructor" << std::endl;
        delete ptr;
    }

    int& operator*() { return *ptr; }
 
    int* operator->() { return ptr; }
};

int main()
{
    SmartPointer sptr(new int(7));

    std::cout << *sptr << std::endl;

    return 0;
}
