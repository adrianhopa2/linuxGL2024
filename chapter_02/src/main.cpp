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

    virtual void foo()
    {
        std::cout << "Parent foo" << std::endl;
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
    void foo() override
    {
        std::cout << "Child foo" << std::endl;
    }
};

int main()
{
    Parent * clazz = new Child;

    clazz->foo();

    delete clazz;

    return 0;
}
