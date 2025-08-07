#include <iostream>
#include <string>

class Entity
{
    public:
    virtual std::string GetName()
    {
        return "Entity";
    };
};

class Player : public Entity
{
    private:
    std::string mem_Name;

    public:
    Player(const std::string& name) : mem_Name(name) {} // constructor using an initializer list.

    std::string GetName() override // add the override keyword to make the code more readable ---> it just signifies a base function has been overriden.
    {
        return mem_Name;
    }
};

int main()
{
    // works as normal ---> both GetName methods do as required
    Entity* e = new Entity();           // entity obj
    std::cout << e->GetName() << '\n';

    Player* p = new Player("Batman");   // player object
    std::cout << p->GetName() << '\n';

    //things go wrong here:
    // essentially an entity pointer pointing to a player object to player behavior expected and player methods expected to be utilized by the entity object
    // Entity* entity = p; 
    // std::cout << entity->GetName() << '\n'; // outputs Entity instead of Batman.

    // essentially functions will be bound to the base class in cases where polymorphism required.

    // reason why method executing is the one inside the Entity class?
    // when func called ---> primary type based output given.
    // will go into the method definition for the type that was passed as an argument. Entuty in our case.
    // virtual functions help cpp know what type of entity is calling the function so as to provide appropriate behavior based on entity type.
    // virtual functions ---> introduce dynamic dispatch which implements the v-table, contains a mapping of the virtual functions in the base class so that we can map it to the correct overwritten function in a subclass.

    // in crux: if function overriding required then mark the base class method as virtual so that the sub classes can override the method correctly despite being within the broader scope.

    // now when we use an entity pointer to store a player obj and call method using entity type player ---> obj specific method will be called rather than the actual implementation in the base class.

    Entity* entity = p;
    std::cout << entity->GetName() << '\n'; // will print Batman instead of Entity.

    /*
    2 runtime costs associated with virtual functions:
        - additional memory to store the v table to dispatch to the correct version of the function, includes the member ptr included in the base class that points to the v table.
        - go through v table each time that method is called.
    */

    return 0;
}