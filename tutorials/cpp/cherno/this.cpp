//this keyword ---> only accessible through a member function
// we can reference 'this' inside a method
// this ---> is a ptr to a currect object instance that the method belongs to.

#include <iostream>
#include <string>

void Print(Entity* e);

class Entity
{
    public:
        int x,y;
        Entity(int x, int y) // we could use an initializer list
        {
            Entity* e = this;   // const in nature in terms of ptr reassignment
            e->x = x;
            this->y = y; // either e or this both work fine
            // -> just derefs the ptr ---> (*this). <---what the arraow operator means.

            this->x = x; // valid too if ptr not explicitly declared using Entity* e = this
            this->y = y;

            // using this ---> we can access functions outside the class from within the class
            Print(this);
        }
        int GetX() const
        {
            const Entity* e = this;
            // e->x = 10; does not allow this
            return this->x;
        }
};

void Print(Entity* e)
{
    // print logic
}

int main()
{
    return 0;
}