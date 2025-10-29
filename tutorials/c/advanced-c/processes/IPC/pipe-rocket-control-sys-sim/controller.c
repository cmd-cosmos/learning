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
    HANDLE hControllerToReaderRead, hControllerToReaderWrite; // controller --> reader command writing pipe 
    HANDLE hReaderToControllerRead, hReaderToControllerWrite; // reader --> controller data writing pipe
    SECURITY_ATTRIBUTES sec_attr = {
        sizeof(SECURITY_ATTRIBUTES),
        NULL,
        TRUE
    };

    WINBOOL controllerToReaderPipeCreation = CreatePipe(&hControllerToReaderRead, &hControllerToReaderWrite, &sec_attr, 0);

    if (!controllerToReaderPipeCreation)
    {
        printf("failed to create controller->reader pipe\n");
        return 1;
    }

    WINBOOL readerToControllerPipeCreation = CreatePipe(&hReaderToControllerRead, &hReaderToControllerWrite, &sec_attr, 0);

    if (!readerToControllerPipeCreation)
    {
        printf("failed to create reader->controller pipe\n");
        return 1;
    }

    // child process info init
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    si.hStdInput = hControllerToReaderRead; // setting up the reader-child processe's input stream
    si.hStdOutput = hReaderToControllerWrite; // reader writes data for the controller parent here
    si.dwFlags |= STARTF_USESTDHANDLES;

    if (!CreateProcess(
        NULL,
        "rc.exe",
        NULL,
        NULL,
        TRUE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    ))
    {
        perror("failed to start reader child process\n");
        return 1;
    }

    CloseHandle(hControllerToReaderRead);
    CloseHandle(hReaderToControllerWrite);

    const char* commands[] = {
        "IDLE",
        "LAUNCH",
        "LAND",
    };

    char buffer[200];
    DWORD written, readBytes;

    for (int i = 0; i < 3; i++)
    {
        WriteFile(hControllerToReaderWrite, commands[i], strlen(commands[i]) + 1, &written, NULL);
        printf("Controller --> Reader Child ==> COMMAND: %s\n", commands[i]);

        SensorData receivedData;
        ReadFile(hReaderToControllerRead, &receivedData, sizeof(SensorData), &readBytes, NULL);
        printf("Reader Child --> Controller ==> READINGS: (TEMP: %.2f, PRES: %.2f, ALT: %.2f, VEL: %.2f)\n",\
        receivedData.temperature,
        receivedData.pressure,
        receivedData.altitude,
        receivedData.velocity);
    }

    CloseHandle(hControllerToReaderWrite);
    CloseHandle(hReaderToControllerRead);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

