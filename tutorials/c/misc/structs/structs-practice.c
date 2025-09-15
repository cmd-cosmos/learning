// some more structs knowledge --> follow along the attached video
// https://www.youtube.com/watch?v=IAvfAC4H_0s

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // struct of arrays
    typedef struct Point
    {
        int x,y;
    }point_t;

    // create an array of structs 
    // point_t array path that will store 5 structs here since no size pre-mentioned
    point_t path[] = {{0,1},{1,2},{2,3},{3,4},{4,5}};

    for (int i = 0; i < 5; i++)
    {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }
    
    return 0;
}