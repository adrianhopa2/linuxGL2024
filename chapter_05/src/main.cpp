#include <iostream>

#include <memory>

template <class T>
class SharedPointer
{
private:
    T *value;

    uint *m_referenceCounter;

public:
    SharedPointer(T *newValue = nullptr) : value(newValue), m_referenceCounter(new uint(0))
    {
        // increment m_referenceCounter only if pointing to a value
        if (value)
        {
            (*m_referenceCounter)++;
        }

        std::cout << "default constructor\t";
        show();
    }

    SharedPointer(SharedPointer &other)
    {
        // copy only if other is pointing to a value
        // else set as nullptr
        if (other.value)
        {
            value = other.value;
            m_referenceCounter = other.m_referenceCounter;
            (*m_referenceCounter)++;
        }
        else
        {
            value = nullptr;
            m_referenceCounter = new uint(0);
        }

        std::cout << "Copying constructor\t";
        show();
    }

    ~SharedPointer()
    {

        if (value)
        {
            (*m_referenceCounter)--;
        }

        std::cout << "destructor\t";
        show();

        if (*m_referenceCounter == 0)
        {
            delete value;
            delete m_referenceCounter;
            std::cout << "memory freed" << std::endl;
        }
    }

    void show()
    {
        if (value)
        {
            std::cout << "m_referenceCounter=" << *m_referenceCounter << "\tvalue=" << *value << std::endl;
        }
        else
        {
            std::cout << "m_referenceCounter=" << *m_referenceCounter << "\tvalue=null" << std::endl;
        }
    }

    void setValue(T n)
    {
        //check if not a nullptr
        if (value)
        {
            *value = n;
        }
    }
};

int main()
{

    SharedPointer sp1(new int(9));
    SharedPointer sp2(sp1);
    SharedPointer sp3(new int(21));
    SharedPointer sp4(sp1);
    SharedPointer sp5(new double(12.8));
    SharedPointer sp6(new char('g'));
    SharedPointer sp7(new std::string("hello"));

    sp2.setValue(7);

    std::cout << "\nsp1: ";
    sp1.show();
    std::cout << "sp2: ";
    sp2.show();
    std::cout << "sp3: ";
    sp3.show();
    std::cout << "sp4: ";
    sp4.show();
    std::cout << "sp5: ";
    sp5.show();
    std::cout << "sp6: ";
    sp6.show();
    std::cout << "sp7: ";
    sp7.show();

    std::cout << "\nend of main()\n";
    std::cout << std::endl;

    return 0;
}