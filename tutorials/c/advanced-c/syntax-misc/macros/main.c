// function like preprocessor macros
// benefits: work well with different types
// embedded sys: avoid function calls, save time on pushes on the stack and avoid jumps but could be done by compiler optimizations

// bad in terms of type checking ---> preprocessors not as strict as regular functions

#include <stdio.h>
#include <stdlib.h>

// function ---> ternary expression as a macro
#define MIN(A, B) (A < B ? A : B)

// wrap args in () to ensure operation done before comparision
// compiles correctly but still wrong functionality
// produces 3 next vals before conlcuding minimum
// the function is called a 3rd time when A or B is selected as A and B will be replaced by the function passed as the argument as can be seen in the example with the valid_min macro call
#define VALID_MIN(A, B) ((A) < (B) ? (A) : (B))

// compound statements in macros ----> allow multiple statements and expressions in one.
// temporary int  vars ---> int _vars
// \ ---> required for macros as macros are one liners and to expand them to multiple lines we need the escape seq.
// to make this macro more flexible change type from int to typeof(A) and typeof(B), just like auto in C++
#define COMPOUND_MIN(A,B) ({\
                            typeof(A) _a = (A); \
                            typeof(B) _b = (B); \
                            _a < _b ? _a : _b;\
                        })

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
    
    // same format, compiles now as args enclosed as separate operations
    #if 0
    
    n3 = VALID_MIN(n1=getNextNum(), n2=getNextNum());
    /*
    Expands to:

    ((n1=getNextNum()) < (n2=getNextNum()) ? (n1=getNextNum()) : (n2=getNextNum()))

    getnextnum called a 3rd time after decision of min made, this happens because preprocessor statements copy and paste code snippets thus even during selection it calls the function as A and B translate to the function calls
    */
    // valid compilation but unwanted behavior
    printf("n3 = %d", n3);
    
    #endif
    
    n3 = COMPOUND_MIN(n1=getNextNum(), n2=getNextNum());
    printf("n3 = %d\n", n3);
    /*
        output:
        next ===> 41
        next ===> 67
        n3 = 41
    */

    return 0;
}