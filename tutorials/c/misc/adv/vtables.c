// polymorphism internals

#include <stdio.h>

typedef struct
{
    void (*speak)(void *);
} VTable;

typedef struct
{
    VTable *v;
    const char *name;
} Animal;

void dog_say(void *self)
{
    printf("%s: woof woof\n", ((Animal*)self)->name);
}

int main(void)
{
    VTable dogVtable = { dog_say };
    Animal dog = { &dogVtable, "Bob" };
    
    dog.v->speak(&dog); 

    return 0;
}
