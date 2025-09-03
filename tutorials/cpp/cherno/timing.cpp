// timing for benchmarking or performance evaluation or defining action timestamp.
// use chrono ---> std lib feature
#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    // utilize object lifetime to create and destroy timer object for individual scopes where the timer object is instantiated
    // std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    std::chrono::time_point<std::chrono::_V2::system_clock> start, end;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << "ms" << std::endl; 
    }
};

// how long does cout take to print the statements to console in the foo function.
void foo()
{
    Timer timer;
    for (int i=0; i < 100; i++)
    {
        std::cout << "I am Batman" << std::endl;
    }
}

// slight optimization --> std::endl flushes buffer thus increasing time, using \n to endline
void bar()
{
    Timer timer;
    for (int i=0; i < 100; i++)
    {
        std::cout << "I am Vengeance\n";
    }
}

int main()
{
    #if 0
    {
        using namespace std::literals::chrono_literals;
        // current time stamp
        auto start = std::chrono::high_resolution_clock::now();
        // making the main thread sleep for a second
        std::this_thread::sleep_for(1s);
        // ending time stamp
        auto end = std::chrono::high_resolution_clock::now();
        // calculating duration with the correct type
        std::chrono::duration<float> duration = end - start;
        // duration in seconds
        std::cout << duration.count() << 's' << std::endl;  
    }
    #endif

    #if 0
    foo(); // Timer took: 45.4755ms
    #endif

    bar(); // Timer took: 8.9816ms

    return 0;
}
