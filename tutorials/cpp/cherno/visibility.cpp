#include <iostream>
#include <string>

class SampleProtected
{
    protected:
        int X_pr = 0;
        void Print_pr() {};
    public:
        float pi = 3.14;
};

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

class Player : public Entity, SampleProtected
{
    Player()
    {
        // X = 10; // error as Player not a friend class to entity so cannot access provate members
        // Print(); // member functons also blocked

        // since it inherits from the SampleProtected class ---> all protected values of the protected class are accessible to classes that inherit from the SampleProtected class
        X_pr = 3;
        Print_pr(); // since these both are protected attributes they can be accessed in the sub class.
        ;
    }
};

int main()
{
    Entity e;
    // e.X = 100; // error --> as X is private in the Entity scope and not modifiable in the gloabl scope.

    SampleProtected sp;
    // sp.X_pr = 100;  // error ---> protected attributes can only be acceced by the classes that inherit from them


    return 0;
}