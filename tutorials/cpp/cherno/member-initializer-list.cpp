// constructor member initializer lists for class constructors
// it is a way to initialize the class member functions inside the constructor.

#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;

    public:
        Entity()
        {
            // default constructor
            m_Name = "Unknown";
        }
        Entity(const std::string& name)
        {
            // constructor that assigns m_Name with the value passed to name during obj instantiation.
            m_Name = name;
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