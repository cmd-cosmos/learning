// supporting both conversions between celcius and fahrenheit

#include <stdio.h>

typedef enum{
ctof, // 0
ftoc // 1
} MODE;

int main()
{
LOOP1:
    double celcius, fahrenheit;
    int inp_mode;

    printf("What conversion do you want to do:\n(0) c->f\n(1) f->c\n");
    printf("Enter Mode[0/1]: ");
    scanf("%d", &inp_mode);

    MODE mode = inp_mode;    

    switch (mode)
    {
    case 0:
        printf("\nCelcius to Farhenheit Converter\n");
        printf("Enter Celcius Val: ");
        scanf("%lf", &celcius);
        fahrenheit = (celcius * ((double) 9 / 5)) + 32;
        printf("Degree Fahrenheit: %.3lf fahrenheit", fahrenheit);
        break;
    case 1:
        printf("\nFarhenheit to Celcius Converter\n");
        printf("Enter Fahrenheit Val: ");
        scanf("%lf", &fahrenheit);
        celcius = ((double) 5 / 9) * (fahrenheit - 32);
        printf("Degree Celcius: %.3lf", celcius);
        break;

    default:
        goto LOOP1;  
    }

    return 0;
}

