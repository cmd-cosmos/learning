// structs in depth ---> with detailed theory.
// knowledge source: https://www.youtube.com/watch?v=qqtmtuedaBM

#include <stdio.h>
#include <string.h>

struct Coordinate
{
    // 2D point representation struct
    float x,y;
};

typedef struct Coordinate coordinates;

int main(int argc, char* argv[])
{
    coordinates point0 = {0.0f, 0.0f};
    printf("(%f,%f)\n", (point0.x,point0.y));

    return 0;
}
