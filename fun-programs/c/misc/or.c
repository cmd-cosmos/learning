// basic truth table for OR operation on 2 operands.

#include <stdio.h>

void boolOR()
{
    int operandA, operandB;
    printf("\nA B | A OR B\n");
    printf("-------------\n");

    for (operandA = 0; operandA <= 1; operandA++){
        for (operandB = 0; operandB <= 1; operandB++){
            int res = operandA || operandB;
            printf("%d %d |   %d\n", operandA, operandB, res);
        }
    }
}

int main()
{
    boolOR();
    return 0;
}