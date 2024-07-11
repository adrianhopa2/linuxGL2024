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


  

    return 0;
}