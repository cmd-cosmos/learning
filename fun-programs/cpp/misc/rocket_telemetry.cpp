// producer consumer based rocket telemetry

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <queue>
#include <condition_variable>

/**
 * @brief Structure for a basic telemetry packet
 * 
 */
typedef struct TelemetryPacket
{
    int packetID;
    double altitude;
    double velocity;
    double temperature;
} TelemetryPacket_t;

std::queue<TelemetryPacket_t> telemetryBuffer;
const size_t MAX_BUFFER_SIZE = 5;

std::mutex bufferMutex;
std::condition_variable bufferNotEmpty;
std::condition_variable bufferNotFull;

std::atomic<bool> missionActive(true);

/**
 * @brief Producer function that puts data into the buffer
 * 
 * @return void
 */
void sensorProd()
{
    int packetCounter = 0;

    while(missionActive)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        TelemetryPacket_t packet;
        packet.packetID     = packetCounter++;
        packet.altitude     = 1000.00 + packetCounter * 50;
        packet.velocity     = 200.00 + packetCounter * 3;
        packet.temperature  = 20.0 + packetCounter * 0.1;
        
        std::unique_lock<std::mutex> lock(bufferMutex);

        bufferNotFull.wait(lock, [] {
            return telemetryBuffer.size() < MAX_BUFFER_SIZE || !missionActive;
        });

        if (!missionActive) {
            break;
        }

        telemetryBuffer.push(packet);
        std::cout << "[PRODUCER] produced: " << packet.packetID << '\n';
        
        lock.unlock();
        bufferNotEmpty.notify_one();
    }
    std::cout << "[PRODUCER] stopped telemetry generation\n";
}

int main(void)
{


    return EXIT_SUCCESS;
}