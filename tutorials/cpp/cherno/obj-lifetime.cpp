// object lifetime - objects on the stack
// lifetime for stack based varaibles

#include <iostream>
#include <string>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Constructior" << '\n';
        }
        ~Entity()
        {
            std::cout << "Destructor" << '\n';
        }
};

int* CreateArray()
{
    // wrong way to create array for external use
    // the array mem is cleaned as soon as function returns

    int array[50];
    return array;
}

class ScopedPtr
// essentially an implementation of the unique ptr.
{
    private:
        Entity*  m_Ptr;
    public:
        ScopedPtr(Entity* ptr) : m_Ptr(ptr)
        {

        }
        ~ScopedPtr()
        {
            delete m_Ptr;
        }
};

int main()
{
    {
                    // object in an empty scope but yet scope bound
        Entity e;   // constructor called
    }               // destructor called here
    // stack entity obj destroyed
     
    // heap allocation ---> Entity creation is scope independent
    // obj not deleted as not explicitly mentioned.
    // OS responsible for mem cleanup after program termination.
    {
        Entity* e = new Entity;
    }

    {
        // this will essentially heap alloc the obj but will make it scope bound as the ptr is a unique or scoped ptr that is not preserved out of scope.
        ScopedPtr e = new Entity();
    }

    return 0;
}

