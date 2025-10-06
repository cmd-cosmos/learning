#include <iostream>
#include <string>

void print(const std::string& brief,const auto& var)
{
    std::cout << "Logger: " << brief << var << std::endl;
}

int main()
{
    int x = 5;
    int *ptr= &x;

    print("x = ",x);
    print("&ptr = ",&ptr);  // addr of the ptr var
    print("ptr = ",ptr);    // val assigned to ptr var
    print("&x = ", &x);     // same as ptr assignment

    return 0;
}