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

character_t createCharacter(int id, char name[100], stats_t stats);


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
    
    // getting number of members in the struct
    int size = sizeof(characters) / sizeof(characters[0]);
    printf("Total active members: %d\n\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("id: %d, name: %s,\nStats:\npower: %d, intelligence: %d\n\n", characters[i].id, characters[i].name, characters[i].stats.power, characters[i].stats.intelligence);
    }

    printf("New Member\n");
    character_t joker = createCharacter(6, "Joker", (stats_t){100,100});
    printf("%d\n", joker.id);
    printf("%s\n", joker.name);
    printf("%d\n", joker.stats.power);
    printf("%d\n", joker.stats.intelligence);

    return 0;
}

// struct generators ---> similar to class initializers in c++
character_t createCharacter(int id, char name[], stats_t stats)
{
    character_t character;
    character.id = id;
    if (name != NULL)
    {
        strcpy(character.name, name);
    }
    else
    {
        strcpy(name, "Default");
    }
    character.stats.power = stats.power;
    character.stats.intelligence = stats.intelligence;
    return character;
}