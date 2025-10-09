// ref:: https://www.youtube.com/watch?v=kiUGf_Z08RQ
// allows to cast to any data type

#include <iostream>
#include <string>

void print(const std::string& brief,const auto& var)
{
    std::cout << "Logger: " << brief << var << std::endl;
}

void print(void* ptr, char type)
{
    switch (type)
    {
    case 'i':
        // handles int pointers
        break;
    case 'c':
        // char ptr handler
        break;
    case 'f':
        // float ptr handler
        break;
    case 'd':
        // double ptr handler
        break;
    default:
        break;
    }
}

int main()
{

    return 0;
}