#include <iostream>
#include <string>

class Entity
{
    private:
        int X, Y;
        void Print() {};

    public:
        Entity()
        {
            X = 0; // modifying private val possible inside the class
        }
};

class Player : public Entity
{
    Player()
    {
        // X = 10; // error as Player not a friend class to entity so cannot access provate members
        // Print(); // member functons also blocked
    }
};

int main()
{
    Entity e;
    // e.X = 100; // error --> as X is private in the Entity scope and not modifiable in the gloabl scope.

    return 0;
}