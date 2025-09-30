// some examples for application based enums

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

typedef enum {
    STAGE_PREP,
    STAGE_LAUNCH,
    FIRST_STAGE_IGNITION,
    STAGE_SEPARATION,
    SECOND_STAGE_IGNITION,
    ORBITAL_INSERTION,
    PAYLOAD_DEPLOY,
    STAGE_COMPLETE,     // mission completion indicator
    STAGE_ABORT,
} RocketPhases_e;

typedef enum{
    NOMINAL,
    WARNING,
    CRITICAL
} Telemetry_e;

void launch(); // launch function ---> main run loop

int main()
{
    srand(time(NULL)); // seed for the random num gen
    printf("=================Launch Console=================\n");
    launch();
    return 0;
}

void launch()
{
    RocketPhases_e phases;

    for (int i = STAGE_PREP; i < STAGE_ABORT; i++)
    {
        phases = i;
        
        if (rand() % 10 == 0)
        {
            printf("Anomaly observed...\n");
            printf("Proceeding with abort sequence...\n");
            phases = STAGE_ABORT;
            break;
        }

        Telemetry_e telemetry = rand() % 3;
        switch (telemetry)
        {
        case NOMINAL:
            printf("Telemetry: nominal observations\n");
            break;
        case WARNING:
            printf("Telemetry: minor anomaly, fault correction active.\n");
            break;
        case CRITICAL:
            printf("Telemetry: CRITICAL FAULT...SWITCHING TO ABORT SEQUENCE\n");
            break;        
        }
        if (telemetry == CRITICAL)
        {
            phases = STAGE_ABORT;
            break;
        }

        switch (phases)
        {
            
            case STAGE_PREP:
                printf("All Systems GO\n");
                sleep(2);
                break;
            case STAGE_LAUNCH:
                printf("Stage Launch Switch ---> Set to Launch\n");
                sleep(5);
                break;
            case FIRST_STAGE_IGNITION:
                printf("Stage 1 Ignition\n");
                sleep(10);
                break;
            case STAGE_SEPARATION:
                printf("Hot Staging Maneauver\n");
                sleep(1);
                break;
            case SECOND_STAGE_IGNITION:
                printf("Stage 2 Ignition\n");
                sleep(5);
                break;
            case ORBITAL_INSERTION:
                printf("Nominal Orbital Insertion\n");
                sleep(4);
                break;
            case PAYLOAD_DEPLOY:
                printf("Payload Deployment Confirmed\n");
                break;
            case STAGE_COMPLETE:
                printf("Another Successful Launch and Landing...\n");
                break;
            case STAGE_ABORT:
                printf("Abort...\n");
                break;
            }
    }

}