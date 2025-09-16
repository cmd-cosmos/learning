// enumerations - collection of ints

#include <stdio.h>
#include <stdlib.h>

enum Sensors
{
    PRESSURE,    // 0
    TEMPERATURE, // 1
    ATTITUDE,    // 2
    ALTITUDE     // 3
};

typedef enum Sensors sensors_t;

int main()
{
    printf("--------------Telementry--------------\n");
    sensors_t sensor_bus;
    printf("Enter Read Target: ");
    scanf("%d", &sensor_bus);

    switch (sensor_bus)
    {
    case PRESSURE:
        printf("Reading Pressures");
        break;
    case TEMPERATURE:
        printf("Reading Temperatures");
        break;
    case ATTITUDE:
    printf("Fetching Attitude Control Policy Results");
    break;
    case ALTITUDE:
        printf("Reading Altitude");
        break;
    default:
        "Cycling Reads";
    }

    return 0;
}
