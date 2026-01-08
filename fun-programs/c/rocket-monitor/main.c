// program to emulate launch countdown

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

struct SpaceShip
{
    int SYS_CODE;
    bool SYS_HEALTH;
};

enum Sensors
{
    GSE,              // GSE health signal
    SEA_ENGINE,       // sea level engine ring health signal
    VAC_ENGINE,      // vaccume level engine ring health signal
    BOOSTER,          // Booster health signal
    SHIP,             // ship health
    SYS_PRESSURE,     // system pressure bit     ---> 1 for nominal pressure readings through subsystems 
    SYS_TEMPERATURE,  // system temperatures bit ---> 1 for nominal temperature readings through subsystems 
    NUM_SENSORS       // total number of sensors on the bus
};

enum SystemHealth
{
    NOMINAL, 
    ABNORMAL,
    FAULT,
    CRITICAL,
    TOTAL_LEVELS
};

typedef enum Sensors sensors_t;
typedef enum SystemHealth systemHealth_t;

systemHealth_t getRandomHealthStatus()
{
    return rand() % TOTAL_LEVELS;
}

int main(void)
{
    srand(time(NULL));
    // access winapi to popup a messagebox --> for fun
    MessageBox(NULL, "Commencing startup health check sequence", "Sequence Alert - Go/No-Go", MB_OKCANCEL);
    
    sensors_t sensorBus;
    systemHealth_t sensorStatus[NUM_SENSORS];
    bool health_ping_permission = 0;
    bool got_input = 0;
    char intermediate_permission_buffer;
    while(got_input == 0)
    {
        printf("Set health ping bit [y/n]: ");
        scanf(" %c", &intermediate_permission_buffer);
        if (intermediate_permission_buffer == 'y' || intermediate_permission_buffer == 'Y')
        {
            health_ping_permission = 1;
            got_input = 1;
        }
        else if (intermediate_permission_buffer == 'n' || intermediate_permission_buffer == 'N')
        {
            printf("Automated health check running...\n");
            printf("Permission required for sensor bus pinging...\n");
            printf("Terminating processes, awaiting health check permission...\n");
            health_ping_permission = 0;
            got_input = 0;
        }
        else
        {
            printf("Invalid Input");
            got_input = 0;
        }

    }
    
    bool health_check_complete = 0;
    if (health_ping_permission == 1)
    {
        printf("----------------------------------------------------------------------\n");
        printf("Access modified ---> Pinging Sensor Bus\n");
        for (int i = 0; i < NUM_SENSORS; i++)
        {
            printf("Health Ping...\n");
            sleep(1);
        }
        printf("----------------------------------------------------------------------\n");
        for (int i = 0; i < NUM_SENSORS; i++)
        {
            printf("STATUS on port %d: ", i);
            sensorBus = i;
            sensorStatus[i] = getRandomHealthStatus();
            
            switch (sensorBus)
            {
                case GSE:
                    printf("Reading GSE health signal ---> %d\n", sensorStatus[i]);
                    break;
                case SEA_ENGINE:
                    printf("Reading Sea Level Engine health signal ---> %d\n", sensorStatus[i]);
                    break;
                case VAC_ENGINE:
                    printf("Reading Vacuume Level Engine health signal ---> %d\n", sensorStatus[i]);
                    break;
                case BOOSTER:
                    printf("Reading Booster health signal from sys integration health port ---> %d\n", sensorStatus[i]);
                    break;
                case SHIP:
                    printf("Reading Ship health signal from sys2 integrated health port ---> %d\n", sensorStatus[i]);
                    break;
                case SYS_PRESSURE:
                    printf("Reading SYSTEM PRESSURE ---> %d\n", sensorStatus[i]);
                    break;
                case SYS_TEMPERATURE:
                    printf("Reading SYSTEM TEMPERATURE ---> %d\n", sensorStatus[i]);
                    break;    
                default:
                    printf("Reading ON PORT %d ---> Unknown Sensor\n", sensorStatus[i]);
                    break;
            }
            sleep(2);
        }    
        printf("----------------------------------------------------------------------\n");
        printf("Health Check ---> Sensor Read Complete\n\n");
        
        bool goNoGo = 1; // assume a go for launch
        health_check_complete = 1;
        for (int i = 0; i < NUM_SENSORS; i++)
        {
            // goNoGo set to 0 only in case of critical error
            // sensorStatus[i] == FAULT || 
            if (sensorStatus[i] == CRITICAL)
            {
                goNoGo = 0; // pre-empt all processes
                break;
            }
        }
        if (goNoGo && health_check_complete)
        {
            printf("System Health: NOMINAL\n");
            printf("Initiating Countdown Sequence...\n");
            for (int i = 10; i >= 0; i--)
            {
                printf("T-minus %d seconds\n", i);
                sleep(1);
            }
            printf("Liftoff...\n");
            printf("----------------------------------------------------------------------\n");
        }
        else
        {
            printf("System Health: ABNORMAL ---> PROCEEDING TO ABORT SEQUENCE\n");
        }
    }

    return 0;
}
