// implicit conversion and explicit keyword.
// implicit conversion ---> compiler automatically performs 1 implicit conversion on our data ---> if a conversion exists for that particular type.
// compiler allowed only 1 implicit conversion
// hard to work with strings as first the const char* array must be casted to the std string and then to entity which involves 2 conversions that the compiler is not allowed, so either type caste a const char* into the std::string and then the compiler will construct an Entity obj using the std string or simply wrap the const char* in the Entity class

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
    int m_Age;
public:
    Entity(const String& name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}

};

int main()
{
    Entity a("Batman");
    Entity b(22); // this must be done
    // Entity b = 22; // not allowed anymore

    // this is also not allowed since explicit kw used with the age parametrized constructor.
                            // Entity c = 30; 
    // compiler implicitly converts this based on the constructor that takes in the age as int
    // from the val of 30 we create an entity obj due to implicit conversion

    // using the explicit keyword
    // it disables the implicit functionality of the compiler


    return 0;
}