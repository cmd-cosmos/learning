// celcius to fahrenheit

#include <stdio.h>

int main()
{
    double celcius, fahrenheit;

    printf("Enter Celcius Val: ");
    scanf("%lf", &celcius);

    fahrenheit = (celcius * ((double) 9 / 5)) + 32;

    printf("Degree Fahrenheit: %.3lf fahrenheit", fahrenheit);

    return 0;
}
