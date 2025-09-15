// structs in depth ---> theory in the notes.txt file.
// knowledge source: https://www.youtube.com/watch?v=qqtmtuedaBM

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// another method to alias struct type alongside the struct declaration and definition
typedef struct Coordinate
{
    // 2D point representation struct
    // 16 bytes reserved
    double x,y;
} coordinates;

// typedef struct Coordinate coordinates;

void Print_Coords(const coordinates* self);

int main(int argc, char* argv[])
{

    // #if 0
    coordinates* point0 = malloc(sizeof(coordinates));
    point0->x = 1.0f;
    point0->y = 2.0f;
    Print_Coords(point0);
    // #endif

    // other method to create a struct type member and pass by ref to the print function
    coordinates point_A;
    point_A.x = 100.0f;
    point_A.y = 200.0f;
    Print_Coords(&point_A);

    coordinates point_origin = { 0 };
    Print_Coords(&point_origin);

    return 0;
}

void Print_Coords(const coordinates* self)
{
    printf("(%f , %f)\n", (*self).x, (*self).y);
}
