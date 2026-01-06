#include <stdio.h>
#include <stdlib.h>

int* allocateNum(){
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
    // freed by caller
}

int main(void){

    int* p = allocateNum();
    printf("%d\n", *p);
    free(p);
}