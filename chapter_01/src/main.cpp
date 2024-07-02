#include <iostream>

class SmartPointer
{
private:
    int myVar;

public:
    SmartPointer(int var = 0) : myVar{var}
    {
        std::cout << "default constructor" << std::endl;
    }

    SmartPointer(const SmartPointer &other) : myVar{other.myVar}
    {
        std::cout << "copy constructor" << std::endl;
    }

    SmartPointer& operator=(const SmartPointer& other)
    {
        if(this != &other)
        {
            myVar = other.myVar;
        }

        std::cout << "copy assignment operator" << std::endl;

        return *this;
    }

    SmartPointer(SmartPointer&& other) noexcept : myVar(other.myVar)
    {
        other.myVar = 0;
        std::cout << "move constructor" << std::endl;
    }

    SmartPointer& operator=(SmartPointer&& other)
    {
        if(this != &other)
        {
            myVar = other.myVar;
            other.myVar = 0;
        }

        std::cout << "move assignment operator" << std::endl;

        return *this;
    }

    ~SmartPointer()
    {
        std::cout << "destructor" << std::endl;
    }

    void getVar()
    {   
        std::cout << "myVar = " << myVar << std::endl;
    }
};

int main()
{
    SmartPointer p(43);
    p.getVar();

    SmartPointer q(p);
    q.getVar();

    SmartPointer r;
    r.getVar();
    r = q;
    r.getVar();

    SmartPointer s = std::move(p);
    s.getVar();
    p.getVar();

    SmartPointer t;
    t = std::move(q);
    t.getVar();
    q.getVar();

    return 0;
}
