// constructor member initializer lists for class constructors
// it is a way to initialize the class member functions and class attributes inside the constructor.
// order is important to the initializer list as attributes will be initialized in order of definition order in the class.
// using a member initializer list ensures in most cases a singular instance of an object is created.
// if we had a default and parametrized constructor ---> both would create separate objects, one with no parameters and 1 with the parameter passed to the parametrized constructor but with an initializer list this can be avoided by simply instantiating with the parameter where required and create a single object.

#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        int m_Score;
    public:
        // Entity()
        // {
        //     // default constructor
        //     m_Name = "Unknown";
        // }
        // we can modify the default constructor to include a member initializer list
        Entity() : m_Name("Unknown"), m_Score(0) // constructor with a member initializer list
        {        

        }
        Entity(const std::string& name) : m_Name(name) //MIL format
        {
            // constructor that assigns m_Name with the value passed to name during obj instantiation.
            // m_Name = name;
            // this also has the member initializer list with the name parameter passed to the member initializer.
        }
        const std::string& GetName() const
        {
            return m_Name;
        }
};

int main()
{
    Entity e_default;
    std::cout << e_default.GetName() << '\n';
    
    Entity e_init("Batman");
    std::cout << e_init.GetName() << '\n';

    return 0;
}