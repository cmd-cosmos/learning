// -> operator for struct and class pointers

#include <iostream>
#include <string>
#include <memory>

class Entity
{
    public:
        int x;
        Entity(){}
        ~Entity(){}
        void Print() const
        {
            std::cout << "class Entity" << std::endl;
        };
};

class ScopedPtr
// essentially automates the deletion of the ptr to the object when scope exited.
{
    private:
        Entity* m_Obj;
    public:
        ScopedPtr(Entity* entity) : m_Obj(entity)
        {
        }
        ~ScopedPtr()
        {
            delete m_Obj;
        }
        Entity* operator->()
        {
            return m_Obj;
        }

};

struct Vector3
{
    float x,y,z;
};


int main()
{
    Entity e;
    e.Print();
    e.x = 100;

    Entity* ptr = &e; // ptr to obj e
    // ptr.Print(); // invalid as ptr is an address, cannot be used for calling object methods
    // ptr.x = 1000; // same error for member var access
    (*ptr).Print(); // deref and call the func
    // or use the -> operator, does the same thing
    ptr->Print(); // works the same as (*ptr).Print();

    ScopedPtr scptr = new Entity();
    scptr->Print(); // we can access obj mem funcs using the scope ptr that will ensure deletion of the object as soon as scope exited

    return 0;
}


