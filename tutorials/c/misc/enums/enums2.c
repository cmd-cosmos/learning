// embedded C programming style
// 1. always typedef enums
// 2. pascal case
// 3. add a suffix like _e to identify as enum

#include <stdio.h>
#include <stdbool.h>

typedef enum{
    PARKED,
    TAXI,
    TAKEOFF,
    CRUISE,
    LAND,
} AircraftState;

typedef struct
{
    int id;    
    char* Name;
    volatile AircraftState state;
}Airline;

void state_logger(AircraftState state){
    switch (state)
        {
        case PARKED:
            printf("Aircraft State: Parked");
            break;
        case TAXI:
            printf("Aircraft State: Taxi");
            break;
        case TAKEOFF:
            printf("Aircraft State: Takeoff");
            break;    
        case CRUISE:
            printf("Aircraft State: Cruise");
            break;
        case LAND:
            printf("Aircraft State: Landing");
            break;
        default:
            printf("Aircraft State: Reading...");
            break;
        }
}

AircraftState readState()
{
    const char* state_map = "0 --> Parked\n"
                            "1 --> Taxi\n"
                            "2 --> Takeoff\n"
                            "3 --> Cruise\n"
                            "4 --> Landing\n";
    printf("%s", state_map);
    printf("Enter val to register state: ");
    int input;
    scanf("%d", &input);
    return (AircraftState)input;
}

int main()
{
    AircraftState state = readState();

    Airline starLines = {.id = 1, .Name = "StarLines", .state = state};

    printf("%d ---> %s ---> ", starLines.id, starLines.Name);
    state_logger(starLines.state);

    return 0;
}