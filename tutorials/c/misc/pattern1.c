// patterns using nested loops

#include <stdio.h>

#define COLUMN 10
#define LINE_BREAK printf("\n")

int main()
{
    for (int i = 0; i < COLUMN; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("&");
        }
        LINE_BREAK;
    }

    LINE_BREAK;
    // inverted right angled triangle pattern
    for (int i = 0; i < COLUMN; i++)
    {
        for(int j = COLUMN-i; j > 0; j--)
        {
            printf("&");
        }
        LINE_BREAK;
    }
}
