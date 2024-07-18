#include <iostream>

#include <memory>

template <class T>
class SharedPointer
{
private:
    T *value;

    // inline static data member can be defined in the class definition and may specify an initializer
    // works a bit better than in chapter_04, because this is in template, so for every type different reference_counter is created
    static inline uint reference_counter = 0;

public:
    SharedPointer(T *newValue = nullptr) : value(newValue)
    {
        reference_counter++;

        std::cout << "default constructor\t";

        if (value)
        {
            show();
        }
        else
        {
            std::cout << "\t\treference_counter=" << reference_counter << std::endl;
        }
    }

    ~SharedPointer()
    {

        std::cout << "destructor\t";

        // check to decrement only when pointer is not null
        if (value)
        {
            reference_counter--;
        }

        show();

        // delete when counter reaches zero
        if (reference_counter == 0)
        {
            delete value;
            std::cout << "memory freed" << std::endl;
        }
    }

    void show()
    {
        if (value)
        {
            std::cout << "reference_counter=" << reference_counter << "\tvalue=" << *value << std::endl;
        }
        else
        {
            std::cout << "reference_counter=" << reference_counter << "\tvalue=null" << std::endl;
        }
    }

    void setValue(T n)
    {
        *value = n;
    }
};

int main()
{

    SharedPointer sp1(new double(25.2));

    SharedPointer sp4(new char('f'));
    SharedPointer sp5(new char('g'));

    std::cout << "\nend of main()\n";
    std::cout << std::endl;

    return 0;
}