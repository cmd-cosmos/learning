// operator overloading ---> overwriting the functionality of the operator
// operator is just a function that works on operands/parameters

#include <iostream>
#include <string>

using String = std::string;

struct Vector2
{
    float x,y;

    Vector2(float x, float y) : x(x) , y(y) {}

    Vector2 add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

        Vector2 operator+(const Vector2& other) const
    {
        return add(other);
    }
    
    Vector2 multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        return multiply(other);
    }

    bool operator==(const Vector2& other) const
    {
        // checking if 2 vectors are equal in magnitude
        return x == other.x && y == other.y;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ',' << other.y;
    return stream;
} 

int main()
{
    Vector2 position(1.0f, 4.0f);
    Vector2 speed(0.35f, 2.0f);
    Vector2 powerup(1.1f, 1.1f);

    // using this paradigm we would need to write the .operation instead of writing equations for each operation like multiply, add ,subtract, divide etc.
    // a.multiply(b) instead of a*b (more readable) 
    Vector2 result = position.add(speed);
    std::cout << "result: " << result.x  << ',' << result.y <<  '\n';

    // using operator overloading to solve the issue.
    Vector2 result2 = position + speed;
    std::cout << "result2: " << result2.x  << ',' << result2.y <<  '\n';

    Vector2 result3 = position + speed * powerup;
    std::cout << "result3: " << result3.x  << ',' << result3.y <<  '\n';

    //overloading the << left shift operator
    // << ---> takes in an output stream and outputs other primitive objects
    // if we want to output the Vector2 obj using this operator we must overload it.
    Vector2 result4 = position + speed;
    std::cout << result4 << '\n'; // now this works as << is overloaded to include custom objects in the regular ostream.

    // == ---> overloading comparator
    std::cout << (result == result3) << std::endl; // false
    std::cout << (result == result2) << std::endl; // true

    return 0;
}