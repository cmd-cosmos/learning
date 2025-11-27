// basic multithreading example

#include <iostream>
#include <thread>
#include <mutex>

std::mutex cout_mtx;

void printNums(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        // critical section of the function
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << i << " -> ";
    }
    std::lock_guard<std::mutex> lock(cout_mtx);
    std::cout << '\n'; 
}

int main()
{
    // both threads write to cout at the same time
    std::thread t1(printNums, 1, 40);
    std::thread t2(printNums, 100, 105);

    t1.join();
    t2.join();

    std::cout << "threads completed.";
    
    return 0;
}

