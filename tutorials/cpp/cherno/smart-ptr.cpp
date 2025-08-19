// smart pointers ---> wrapper for raw pointers
// automatically allocates and frees memory
// Eg) Unique ptr ---> type of smart ptr. Scoped ptr --> as soon as the ptr goes out of scope it will delete automatically.
// unique ptrs cannot be copied ---> if we have a copy of a unique ptr it will pt to the same location and when 1 unique ptr goes out of scope, it deletes the data in that memory so the copy is pointing to deleted/freed memory.
// unique pointer uses reference counting underneath in most of the cases

#include <iostream>
#include <string>
#include <memory>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity" << '\n';
        }
        ~Entity()
        {
            std::cout << "Destroyed Entity" << '\n';
        }
        void Print()
        {
            std::cout << "Print function" << '\n';
        }
};

int main()
{
    {
        // empty scope
        // first method to create a unique ptr
        std::unique_ptr<Entity> e(new Entity());
        e->Print();
    }

    {
        // exception safe method to create a unique ptr
        // avoids a scenario with a dangling ptr and thus avoids mem leaks
        std::unique_ptr<Entity> e = std::make_unique<Entity>();
        e->Print();
    }

    return 0;
}

