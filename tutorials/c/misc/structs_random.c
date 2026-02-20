#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t x;
    uint32_t y;
} vector_t;

typedef struct
{
    char* name;
    uint32_t age;
} student_t;

int main(void)
{
    vector_t vec = { 1,10 };
    printf("%d\n",vec.x);
    printf("%d\n",vec.y);
    printf("sizeof struct vector = %zu bytes\n", sizeof(vector_t));
    printf("sizeof vec = %zu bytes\n", sizeof(vec));

    student_t* s1 = malloc(sizeof(student_t));
    s1->name = "batman";
    s1->age = 22;

    printf("student name: %s\n", (*s1).name);
    printf("student age: %d\n", (*s1).age);

    student_t* s2 = malloc(sizeof(student_t));
    s2->name = "joker";
    s2->age = 25;

    printf("student name: %s\n", s2->name);
    printf("student age: %d\n", s2->age);

    return 0;
}