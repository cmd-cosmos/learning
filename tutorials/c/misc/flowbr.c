// using break to break out of a loop

#include <stdio.h>

int main()
{
    int i, inp, upper_bound;
    i = 0;
    upper_bound = 100; // inclusive
    printf("Enter num: ");
    scanf("%d", &inp);

    for (; i <= upper_bound; i++)
    {
        if (i == inp)
        {
            printf("Number in range.");
            break;
        }
    } 
    if (i > upper_bound)
    {
        printf("Not in Range.");
    }
    return 0;
}