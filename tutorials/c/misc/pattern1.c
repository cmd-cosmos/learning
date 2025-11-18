// patterns using nested loops

#include <stdio.h>

#define COLUMN 10

int main()
{
    for (int i = 0; i < COLUMN; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("&");
        }
        printf("\n");
    }


    return 0;
}


