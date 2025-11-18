// farenheit to celcius 

#include <stdio.h>

int main()
{
    double celcius, fahrenheit;

    printf("Enter Fahrenheit Val: ");
    scanf("%lf", &fahrenheit);

    celcius = ((double) 5 / 9) * (fahrenheit - 32);

    printf("Degree Celcius: %.3lf", celcius);

    return 0;
}