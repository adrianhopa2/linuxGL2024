#include <iostream>
#include <thread>

int main()
{
    auto philosopher = [](std::string name, std::mutex &mutexA, std::mutex &mutexB, unsigned int buffer)
    {
        while (buffer)
        {
            mutexA.lock();

            // philosopher eats only when both mutexes are locked, otherwise unlocks mutexA
            if (mutexB.try_lock())
            {
                std::cout << "Philosopher " << name << " started eating - spaghetti left: " << buffer << std::endl;

                buffer--;
                std::this_thread::sleep_for(std::chrono::seconds(1));

                std::cout << "\tPhilosopher " << name << " stopped eating - spaghetti left: " << buffer << std::endl;

                mutexB.unlock();
            }

            mutexA.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << "\t\tPhilosopher " << name << " ate all his spaghetti" << std::endl;
    };

    std::mutex mutex1, mutex2, mutex3, mutex4, mutex5;

    std::jthread thread1(philosopher, "12", std::ref(mutex1), std::ref(mutex2), 4);
    std::jthread thread2(philosopher, "23", std::ref(mutex2), std::ref(mutex3), 3);
    std::jthread thread3(philosopher, "34", std::ref(mutex3), std::ref(mutex4), 5);
    std::jthread thread4(philosopher, "45", std::ref(mutex4), std::ref(mutex5), 6);
    std::jthread thread5(philosopher, "15", std::ref(mutex1), std::ref(mutex5), 7);
    // all philosophers first lock mutexA, then try to lock mutexB
    // to prevent deadlock after all philosophers lock mutexA, they cant all have different mutexA
    // so the order of mutexes for philosopher5 is swapped:
    // order changed from 
    // ..., mutex5, mutex1, ...
    // to 
    // ..., mutex1, mutex5, ...
    // then philosopher1 and philosopher5 have the same mutexA 
    // so philosopher5 can lock mutexA only when it is not locked by philosopher1

    return 0;
}
