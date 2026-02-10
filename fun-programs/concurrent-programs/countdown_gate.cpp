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

void launch_control()
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "[LC] Waiting for Engine Ready\n";

    cv.wait(lock, [] { return engine_ready; });
    std::cout << "[LC] Engine Ready - Ignition Seq\n";

}

int main()
{
    std::thread engine(engine_chill);
    std::thread lc(launch_control);

    engine.join();
    lc.join();
}