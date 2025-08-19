// copy and copy constructors

#include <iostream>
#include <string>
#include <memory>

struct Vector2
{
    int x,y;
};


int main()
{
    int a = 3;
    int b = a;

    b = 25; // a is still 3 since b is a copy of a 


    Vector2* v1 = new Vector2();
    Vector2* v2 = v1;
    // we can modify what v2 points towards, but any mod done using v2 will impact v1 attributes as both pointers point to the same object.
    std::cout << "v1: " << v1->x << '\n';
    std::cout << "v2: " << v2->x << '\n';

    v2->x = 100;
    std::cout << "v1: " << v1->x << '\n';
    std::cout << "v2: " << v2->x << '\n';

    return 0;
}


