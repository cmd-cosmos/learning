// program to emulate 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>

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

typedef enum Sensors sensors_t;

int main(void)
{
    sensors_t sensorBus;

    bool health_ping_permission = 0;
    bool got_input = 0;
    char intermediate_permission_buffer;
    while(got_input == 0)
    {
        printf("Set health ping bit [y/n]: ");
        scanf("%s", &intermediate_permission_buffer);
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
        for (int i = 0; i < NUM_SENSORS; i++)
        {
            printf("Health Ping...\n");
            sleep(1);
        }
        for (int i = 0; i < NUM_SENSORS; i++)
        {
            printf("PING on port %d: ", i);
            sensorBus = i;
            
            switch (sensorBus)
            {
                case GSE:
                    printf("Reading GSE health signal...\n");
                    break;
                case SEA_ENGINE:
                    printf("Reading Sea Level Engine health signal...\n");
                    break;
                case VAC_ENGINE:
                    printf("Reading Vacuume Level Engine health signal...\n");
                    break;
                case BOOSTER:
                    printf("Reading Booster health signal from sys integration health port...\n");
                    break;
                case SHIP:
                    printf("Reading Ship health signal from sys2 integrated health port...\n");
                    break;
                case SYS_PRESSURE:
                    printf("Reading SYSTEM PRESSURE...\n");
                    break;
                case SYS_TEMPERATURE:
                    printf("Reading SYSTEM TEMPERATURE...\n");
                    break;    
                default:
                printf("Pinging...\n");
                break;
            }
            sleep(1);
        }    
    }

    return 0;
}
