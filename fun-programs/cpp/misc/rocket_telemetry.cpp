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

int main(void)
{


    return EXIT_SUCCESS;
}