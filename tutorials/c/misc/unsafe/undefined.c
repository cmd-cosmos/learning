// undefined behavior due to unint vals

#include <stdio.h>

int main(void)
{
    double gyroReading;
    if (gyroReading > 0.01)
    {
        puts("Gyro --> Turn");
    }
    else{
        puts("Gyro --> No action needed");
    }
    return 0;
}
/*
Output: as no vals were initialized
Gyro --> No action needed 
*/