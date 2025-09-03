// multithreading in cpp ---> parralellize computations by multithreaded execution
#include <iostream>
#include <thread>

static bool s_Finished = false;

void Work()
{
    //function that the worker thread will execute in parallel to the main run loop
    while (!s_Finished)
    {
        // keep logging the worker thread output while waiting for input to kill execution
        std::cout << "Working thread..." << std::endl;
    }
}

int main()
{
    // main thread ---> starts the worker thread
    std::thread worker(Work);
    
    std::cin.get();     // this thread waits for enter key input
    s_Finished = true;  // when enter pressed we advance to this line


    worker.join();      // makes sure we do not print the main and worker execution complete until the while loop has been exited.
    // .join() makes the main thread to wait for the worker thread to finish its execution before we continue the main thread execution
    
    std::cout << "main and worker execution complete." << std::endl;
    std::cin.get(); // good exit point for the program
    return 0;

}