// pure virtual functions ---> interfaces in java or abstract method in other languages

#include <iostream>
#include <string>

// a class is known as an interface when it only contains unimplemented methods.
class Printable
{
    public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
    public:
    virtual std::string GetName() {return "Entity";}
    std::string GetClassName() {return "Entity";}
};

class Player : public Entity
{
    private:
    std::string mem_Name;

    public:
    Player(const std::string& name) : mem_Name(name) {} // constructor using an initializer list.

    std::string GetName() override
    {
        return mem_Name;
    }

    std::string GetClassName() override
    {
        return("Player");
    }

};
void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
};

int main()
{
    Entity* e = new Entity();
    Player* p = new Player("Batman");

    // calling functions to print the class name.
    Print(e);
    Print(p);

    return 0;
}
