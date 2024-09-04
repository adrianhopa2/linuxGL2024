#include <iostream>
#include <thread>

int main()
{
    uint var = 70;
    std::mutex t_mutex;

    auto func = [&](int id)
    {
        bool active = true;
        while (active)
        {
            for (int i = 0; i < 10; i++)
            {
                std::lock_guard<std::mutex> guard(t_mutex);

                if (var == 0)
                {
                    active = false;
                    break;
                }
                std::cout << "Thread " << id << ", logging " << var << std::endl;

                var--;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    };

    std::jthread t1(func, 1);
    std::jthread t2(func, 2);
    std::jthread t3(func, 3);

    while (true)
    {
        if (var == 0)
        {
            std::cout << "Buffer is empty, program is terminating." << std::endl;
            break;
        }
    }

    return 0;
}
