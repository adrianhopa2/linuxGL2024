#include <iostream>
#include <memory>
using namespace std;

class customIntAllocator
{
private:
    int value;

public:
    customIntAllocator(int v = 0) : value{v}
    {
        std::cout << "Custom Int Allocated" << std::endl;
    }

    ~customIntAllocator()
    {
        std::cout << "Custom Int Destructor" << std::endl;
    }

    int getInt()
    {
        return value;
    }

};

class Test
{
private:
    int x;
    int y;

public:
    Test(int X = 0, int Y = 0) : x{X}, y{Y} {}

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class customTestClassAllocator
{
private:
    Test t;

public:
    customTestClassAllocator(Test T = Test()) : t{T}
    {
        std::cout << "Custom Test object Allocated" << std::endl;
    }

    ~customTestClassAllocator()
    {
        std::cout << "Custom Test object Destructor" << std::endl;
    }

    Test getTest()
    {
        return t;
    }
};



int main()
{
    // custom deleter
    std::shared_ptr<int> ptr(new int(42), [](int *storedValue)
                             { 
        std::cout << "deleting" << std::endl;
        delete storedValue; });

    std::cout << ptr.use_count() << std::endl;
    std::cout << *ptr << std::endl << std::endl;


    //custom int allocator
    shared_ptr<customIntAllocator> ptr2 = std::make_shared<customIntAllocator>(42);

    std::cout << ptr2.use_count() << std::endl;
    std::cout << ptr2->getInt() << std::endl << std::endl;


    //custom class allocator
    shared_ptr<customTestClassAllocator> ptr3 = std::make_shared<customTestClassAllocator>(Test(2, 4));

    std::cout << ptr3.use_count() << std::endl;
    std::cout << ptr3->getTest().getX() << " " << ptr3->getTest().getY() << std::endl << std::endl;

  

    return 0;
}