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
        print("cast int and deref: ", *((int*)ptr));
        break;
    case 'c':
        // char ptr handler
        print("cast char and deref: ", *((char*)ptr));
        break;
    case 'f':
        // float ptr handler
        print("cast float and deref: ", *((float*)ptr));
        break;
    case 'd':
        // double ptr handler
        print("cast double and deref: ", *((double*)ptr));
        break;
    default:
        print("wrong type passed: ", type);
        break;
    }
}

int main()
{
    int num = 10;
    char letter = 'a';
    float flt = 3.14f;
    double db = 2.718;

    print(&num, 'i');
    print(&letter, 'c');
    print(&flt, 'f');
    print(&db, 'd');
    print(&db, 't'); // passing the wrong type

    return 0;
}