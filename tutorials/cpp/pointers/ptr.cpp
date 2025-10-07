#include <iostream>
#include <string>

void print(const std::string& brief,const auto& var)
{
    std::cout << "Logger: " << brief << var << std::endl;
}

int main()
{
    // ptr and pointee must be of same type
    int x = 5;
    int *ptr= &x;

    print("x = ",x);
    print("&ptr = ",&ptr);  // addr of the ptr var
    print("ptr = ",ptr);    // val assigned to ptr var
    print("&x = ", &x);     // same as ptr assignment

    // deref
    print("*ptr = ", *ptr);

    // deref + modify
    *ptr += 10;
    print("modified x = ", x);
    print("modified ptr deref = ", *ptr);

    // ptr arithmatic
    std::string array[5] = {
        "Batman", "Alfred", "Robin", "Joker", "Scarecrow"
    };
    print("&array[0] = ", array);
    print("array = ", array);

    print("array[0] = ", array[0]);
    print("*array  = ", *array);

    print("*(array + 1) = ", *(array + 1));

    return 0;
}