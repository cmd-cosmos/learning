// basic multithreading example

#include <iostream>
#include <thread>

void printNums(int start, int end)
{
    for (int i = 0; i <= end; i++)
    {
        std::cout << i << " -> ";
    }
    std::cout << '\n'; 
}

int main()
{
    // both threads write to cout at the same time
    std::thread t1(printNums, 1, 10);
    std::thread t2(printNums, 10, 20);

    t1.join();
    t2.join();

    std::cout << "threads completed.";
    
    return 0;
}

