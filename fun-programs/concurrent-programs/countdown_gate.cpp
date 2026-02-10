// condition var countdown gate

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool engine_ready = false;

void engine_chill()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    {
        std::lock_guard<std::mutex> lock(mtx);
        engine_ready = true;
    }
    std::cout << "[ENGINE] Chilldown Complete\n";
    cv.notify_one();
}
