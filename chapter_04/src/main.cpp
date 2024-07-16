#include <iostream>

class SharedPointer
{
private:
    int *value;
    static uint reference_counter;

public:
    SharedPointer(int *newValue = nullptr) : value(newValue)
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

    SharedPointer(const SharedPointer &other) : value(other.value)
    {
        reference_counter++;
        std::cout << "Copying constructor\t";
        show();
    }

    SharedPointer &operator=(const SharedPointer &other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        std::cout << "Copying operator\t";
        show();
        return *this;
    }

    SharedPointer(SharedPointer &&other) noexcept : value(other.value)
    {
        other.value = nullptr;
        // no need to decrement reference_counter because this move constructor didnt increment reference_counter when creating new object
        std::cout << "Moving constructor\t";
        show();
    }

    SharedPointer &operator=(SharedPointer &&other)
    {
        if (this != &other)
        {
            value = other.value;
            other.value = nullptr;
            reference_counter--;
            // decrement reference_counter because other became null and new object was created using default constructor that increments reference_counter
        }
        std::cout << "Moving operator \t";
        show();
        return *this;
    }

    void show()
    {
        if (value)
        {
            std::cout << "value=" << *value << "\treference_counter=" << reference_counter << std::endl;
        }
        else
        {
            std::cout << "value=null\treference_counter=" << reference_counter << std::endl;
        }
    }

    void setValue(int n)
    {
        *value = n;
    }
};

// initialize counter
uint SharedPointer::reference_counter{0};

int main()
{
    std::cout << std::endl;

    // copy constructor and copy operator
    SharedPointer sp0(new int(25));
    SharedPointer sp1(sp0);
    SharedPointer sp2;
    sp2 = sp1;
    sp1.setValue(18);
    std::cout << "sp0: ";
    sp0.show();
    std::cout << "sp1: ";
    sp1.show();
    std::cout << "sp2: ";
    sp2.show();

    std::cout << std::endl;

    // move constructor
    SharedPointer sp3(std::move(sp1));
    std::cout << "sp0: ";
    sp0.show();
    std::cout << "sp1: ";
    sp1.show();
    std::cout << "sp2: ";
    sp2.show();
    std::cout << "sp3: ";
    sp3.show();

    std::cout << std::endl;

    // move operator
    SharedPointer sp4;
    sp4 = std::move(sp3);
    std::cout << "sp0: ";
    sp0.show();
    std::cout << "sp1: ";
    sp1.show();
    std::cout << "sp2: ";
    sp2.show();
    std::cout << "sp3: ";
    sp3.show();
    std::cout << "sp4: ";
    sp4.show();

    std::cout << "\nend of main()\n";
    std::cout << std::endl;

    return 0;
}