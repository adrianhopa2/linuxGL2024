#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent constructor" << std::endl;
    }

    //if the destructor isn't virtual deleting derived class object won't call derived class destructor
    virtual ~Parent()
    {
        std::cout << "Destructing Parent" << std::endl;
    }

    virtual void foo(int i)
    {
        std::cout << "Parent foo " << i << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child constructor" << std::endl;
    }

    ~Child()
    {
        std::cout << "Destructing Child" << std::endl;
    }

    //override forces to override function from parent
    void foo(int i) override
    {
        std::cout << "Child foo " << i << std::endl;
    }
};

int main()
{
    Parent * clazz = new Child;

    //function from child is called
    clazz->foo(83);

    delete clazz;

    return 0;
}
