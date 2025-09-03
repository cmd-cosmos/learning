// multithreading in cpp ---> parralellize computations by multithreaded execution
#include <iostream>
#include <thread>

static bool s_Finished = false;

void Work()
//function that the worker thread will execute in parallel to the main run loop
{
    // namespace to allow for 1s input to thread sleep
    using namespace std::literals::chrono_literals;
    //thread id
    std::cout << "Worker thread - id: " << std::this_thread::get_id() << std::endl;
    while (!s_Finished)
    {
        // keep logging the worker thread output while waiting for input to kill execution
        // if function runs at its fastest speed then chances for 100% CPU usage possible ---> add a sleep command for the thread between each iteration
        std::cout << "Working thread..." << std::endl;
        std::this_thread::sleep_for(1s); // thread sleeps for 1s
    }
}

int main()
{
    std::cout << "Main thread - id: " << std::this_thread::get_id() << std::endl;

    // main thread ---> starts the worker thread
    std::thread worker(Work);

    std::cin.get();     // this thread waits for enter key input
    s_Finished = true;  // when enter pressed we advance to this line
    worker.join();      // makes sure we do not print the main and worker execution complete until the while loop has been exited.
    // .join() makes the main thread to wait for the worker thread to finish its execution before we continue the main thread execution
    std::cout << "Main thread - id: " << std::this_thread::get_id() << std::endl;
    std::cout << "main and worker execution complete. Press Enter to exit" << std::endl;
    std::cin.get(); // good exit point for the program
    return 0;

}