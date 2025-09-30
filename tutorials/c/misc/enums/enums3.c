// some examples for application based enums

#include <stdio.h>
#include <unistd.h>

typedef enum {
    STAGE_PREP,
    STAGE_LAUNCH,
    FIRST_STAGE_IGNITION,
    STAGE_SEPARATION,
    SECOND_STAGE_IGNITION,
    ORBITAL_INSERTION,
    PAYLOAD_DEPLOY,
    STAGE_ABORT,
} RocketPhases;

int main()
{
    RocketPhases phases;

    for (int i = STAGE_PREP; i < STAGE_ABORT; i++)
    {
        phases = i;
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
        case STAGE_ABORT:
            printf("Abort...\n");
            break;
        }
    }

    return 0;
}