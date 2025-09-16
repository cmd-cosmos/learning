// some more structs knowledge --> follow along the attached video
// https://www.youtube.com/watch?v=IAvfAC4H_0s

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stats
{
    int power;
    int intelligence;
}stats_t;


typedef struct Character
{
    int id;
    char name[100];
    stats_t stats;
}character_t;


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

    character_t characters[] = {
        {1, "Batman", {100,100}},
        {2, "Superman", {99,80}},
        {3, "Wonder Woman", {98,90}},
        {4, "Green Lantern", {95,98}},
        {5, "Flash", {95,70}},
    };
    printf("---------Justice League Database---------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("id: %d, name: %s,\nStats:\npower: %d, intelligence: %d\n\n", characters[i].id, characters[i].name, characters[i].stats.power, characters[i].stats.intelligence);
    }
    
    return 0;
}