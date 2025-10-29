#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    float temperature;
    float pressure;
    float altitude;
    float velocity;
} SensorData;

int main()
{
    char command[20];
    DWORD readBytes, written;

    while (1)
    {
        if (!ReadFile(GetStdHandle(STD_INPUT_HANDLE), command, sizeof(command), &readBytes, NULL) || readBytes == 0)
        {
            break;
        }
        printf("CONTROLLER --> READER ==> COMMAND: %s\n", command);

        SensorData data;
        if (strcmp(command, "IDLE") == 0)
        {
            data.temperature = 10.0;
            data.pressure = 120.0;
            data.altitude = 0.0;
            data.velocity = 0.0;
        }
        else if (strcmp(command, "LAUNCH") == 0)
        {
            data.temperature = 13.0;
            data.pressure = 200.0;
            data.altitude = 10.0;
            data.velocity = 200.0;
        }
        else if (strcmp(command, "LAND") == 0)
        {
            data.temperature = 20.0;
            data.pressure = 180.0;
            data.altitude = 400.0;
            data.velocity = 330.0;
        }

        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &data, sizeof(SensorData), &written, NULL);
    }
    

    return 0;
}

