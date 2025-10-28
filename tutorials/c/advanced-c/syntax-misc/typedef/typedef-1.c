// basics of typedef structs
// typedfe --> gives an existing type a nickname

#include <stdio.h>

// essentially a string with 25 bytes allocated
typedef char name[25]; // char array of 25 bytes of memory

struct noobCharacter
{
    char first_name[25];
    char last_name[25];
    int code;
};

struct proCharacter
{
    char first_name[25];
    char last_name[25];
    int code;
};

// now the proCharacter identifier can be used for variable assignment and declarations
typedef struct proCharacter pro;

int main(int argc, char* argv[])
{
    name user1 = "Batman"; // instead of using char array use name

    // since we did not typedef this struct --> verbose declaration
    struct noobCharacter character = {"Bruce", "Wayne", 42};

    // custom data type can be used to shorten declarations
    // sort of a macro
    pro character2 = {"Batman", "Gotham", 21};

    printf("%s\n", character.first_name);
    printf("%s\n", character.last_name);
    printf("%d\n", character.code);
    printf("%s\n", character2.first_name);
    printf("%s\n", character2.last_name);
    printf("%d\n", character2.code);
 
}