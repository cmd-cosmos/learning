#include <iostream>
#include <string>

void print(const std::string& brief,const auto& var)
{
    std::cout << "Logger: " << brief << var << std::endl;
}

void printNum(int* num)
{
    // std::cout << "deref and print from functions: " << *num << std::endl;
    print("int pass by ref ---> ", *num);
}

void printChar(char* letter)
{
    print("char pass by ref ---> ", *letter);
}

int main()
{
    int x = 5;
    char letter = 'a';

    printNum(&x);
    printChar(&letter);

    return 0;
}
