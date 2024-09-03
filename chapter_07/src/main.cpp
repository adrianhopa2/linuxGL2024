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
            
            if (t_mutex.try_lock())
            {
                for (int i = 0; i < 10; i++)
                {

                    if (var == 0)
                    {
                        t_mutex.unlock();
                        active = false;
                        break;
                    }
                    std::cout << "Thread " << id << ", logging " << var << std::endl;
                    var--;
                }

                

                t_mutex.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            
        }
    };

    std::thread t1(func, 1);
    std::thread t2(func, 2);
    std::thread t3(func, 3);

    t1.join();
    t2.join();
    t3.join();

    if (var == 0)
    {
        std::cout << "Buffer is empty, program is terminating." << std::endl;
    }

    return 0;
}
