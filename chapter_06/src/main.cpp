#include <iostream>
#include <type_traits>

// example class test1
class Test
{
private:
    int x;
    int y;

public:
    Test(int X, int Y) : x(X), y(Y) {}

    void show()
    {
        std::cout << "X:" << x << "\tY:" << y << std::endl;
    }
};

// example class test2
class Test2
{
private:
    double x;
    double y;

public:
    Test2(double X, double Y) : x(X), y(Y) {}

    void show()
    {
        std::cout << "X:" << x << "\tY:" << y << std::endl;
    }
};

// SharedPointer that's only for types that are classes, using enable_if with is_class from type_traits
template <typename T, typename = typename std::enable_if<std::is_class<T>::value>::type>
class ClassSharedPointer
{
private:
    T *value;
    uint *m_referenceCounter;

public:
    ClassSharedPointer(T *newValue = nullptr) : value(newValue), m_referenceCounter(new uint(0))
    {
        if (value)
        {
            (*m_referenceCounter)++;
        }

        std::cout << "default constructor\tm_referenceCounter=" << *m_referenceCounter << "\t";
        show();
    }

    ClassSharedPointer(ClassSharedPointer &other)
    {
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

        std::cout << "Copying constructor\tm_referenceCounter=" << *m_referenceCounter << "\t";
        show();
    }

    ~ClassSharedPointer()
    {

        if (value)
        {
            (*m_referenceCounter)--;
        }

        std::cout << "destructor\t\tm_referenceCounter=" << *m_referenceCounter << "\t";
        show();

        if (*m_referenceCounter == 0)
        {
            delete value;
            delete m_referenceCounter;
            std::cout << "memory freed" << std::endl;
        }
    }

    // using function from class
    void show()
    {
        value->show();
    }

    void setValue(T n)
    {
        if (value)
        {
            *value = n;
        }
    }
};

// simple templated function that outputs input value
template <typename T>
void showValue(T value)
{
    std::cout << "MyValues is " << value << std::endl;
}

// template specialization for bool
template <>
void showValue(bool value)
{
    std::cout << "MyValues is " << (value ? "true" : "false") << std::endl;
}

// logging function for simple data types only (not class) using enable_if with !is_class
template <typename T, typename std::enable_if<!std::is_class<T>::value, T>::type = 0>
void logSimpleType(T val)
{
    std::cout << "logging value: " << val << std::endl;
}

int main()
{
    int a{8};
    double b{3.14};
    char c{'m'};
    bool d{true};
    showValue(a);
    showValue(b);
    showValue(c);
    showValue(d);

    ClassSharedPointer sp1(new Test(2, 3));
    ClassSharedPointer sp2(new Test2(3.14, 2.7));

    logSimpleType(a);
    logSimpleType(c);

    return 0;
}
