// function like preprocessor macros
// benefits: work well with different types
// embedded sys: avoid function calls, save time on pushes on the stack and avoid jumps but could be done by compiler optimizations

// bad in terms of type checking ---> preprocessors not as strict as regular functions

#include <stdio.h>
#include <stdlib.h>

// function ---> ternary expression as a macro
#define MIN(A, B) (A < B ? A : B)

// wrap args in () to ensure operation done before comparision
#define VALID_MIN(A, B) ((A) < (B) ? (A) : (B))

int getNextNum()
{
    int nextNum = rand() % 100;
    printf("next ===> %d\n", nextNum);
    return nextNum;
}

int main()
{
    printf("%d\n", MIN(3,8));
    printf("%f\n", MIN(3.14,100.011));
    
    int n1, n2, n3;

    // will not compile due to ambiguity of assignment
    // n3 = MIN(n1=getNextNum(),n2=getNextNum());
    // translate to ---> (n1=getNextNum() < n2=getNextNum() ? n1=getNextNum() : n2=getNextNum())
    // printf("%d\n", n3);
    
    // same format, works now as  args enclosed as separate operations
    n3 = VALID_MIN(n1=getNextNum(), n2=getNextNum());

    
    return 0;
}