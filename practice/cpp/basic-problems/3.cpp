// reversing a string

#include <iostream>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    int i,j,len;
    char string[MAX_SIZE];
    char rev_string[MAX_SIZE];

    std::cout << "Enter String: ";
    std::cin >> string;

    len = strlen(string); // strlen --> does not include the null escape char
    std::cout << len << '\n';
    j = 0;

    for (i = len - 1; i >= 0; i--)
    {
        rev_string[j] = string[i];
        j++;
    }
    rev_string[j] = '\0'; // null terminate the reversed string
    std::cout << "Reversed String: " << rev_string;
    return 0;
}