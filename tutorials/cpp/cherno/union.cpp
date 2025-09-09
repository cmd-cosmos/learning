// Unions
// similar to structs in syntax, but all members share the same memory.
// only one member can hold a meaningful value at a time.
// size of a union equals size of largest member (plus possible padding).
// commonly used for type punning or memory optimization.
// cannot have virtual functions or base classes.
// anonymous/unnamed unions are allowed inside classes or globally.
// accessing a member that was not most recently written to --> undefined behavior

#include <iostream>
#include <string>

struct Vector2
{
    float x,y;
};

struct Vector4
// for this example Vector4 can be considered as 2 Vector2's
{
    // 2 Vector2's with x,y and z,w as being members of vector2 obj
    union 
    {
        // only 4 bytes of mem allocated to all 4 members and only 1 can be active in memory at a moment if encapsulated in a union, so put in a struct and the union assigns 16 bytes for the single active member which will be an anonymous struct
        struct 
        // this struct will be allocated 16 bytes of memory
        {
            float x,y,z,w;
        };
        struct 
        // another member of the union that will share the 16 byte mem space
        // only 1 struct will be active at any time
        // this allows for type punning by assigning the x,y to vector2 a and z,w to vector2 b
        {
            Vector2 a,b;
        };
        
    }
;
    
};

void PrintVector2(const Vector2& vector)
{
    std::cout << vector.x << ',' << vector.y << '\n';
}

int main()
{
    #if 0
    union
    {
        float a;
        int b;
    };
    #endif

    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    std::cout << vector.x << std::endl;
    std::cout << vector.y << std::endl;
    std::cout << vector.z << std::endl;
    std::cout << vector.w << std::endl;

    std::cout << "--------------------------" << '\n';
    PrintVector2(vector.a); // prints Vector4 x and y memebers
    PrintVector2(vector.b); // prints Vector4 z and w memebers
    // modifying members using format for struct number 1 in the union members for Vector4 
    vector.x = 200.0f;
    vector.y = 120.0f;
    std::cout << "--------------------------" << '\n';
    // using vector2 print method to show shared nature of memory
    PrintVector2(vector.a);
    PrintVector2(vector.b);


    return 0;
}
