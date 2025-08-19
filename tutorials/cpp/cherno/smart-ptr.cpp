// smart pointers ---> wrapper for raw pointers
// automatically allocates and frees memory
// Eg) Unique ptr ---> type of smart ptr. Scoped ptr --> as soon as the ptr goes out of scope it will delete automatically.
// unique ptrs cannot be copied ---> if we have a copy of a unique ptr it will pt to the same location and when 1 unique ptr goes out of scope, it deletes the data in that memory so the copy is pointing to deleted/freed memory.

// Shared pointer ---> since unique pointers can not be shared, shared pointers cater to that requirement.
// internal implementation: reference counting in majority cases but is compiler dependent and std lib dependent.
// ref counting keeps track of num of refs to the pointer, as soon as that val reaches 0, ptr is deleted. 
// ref count is stored on the control block which is a mem overhead when shared ptrs are declared.
// shared pointer to shared ptr copy affects the ref counts but when we use weak ptrs with shared ptrs ---> ref count not affected.

// unique pointer is 1st preference and then shared pointers

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

    {
        std::shared_ptr<Entity> e_scopeout;
        std::weak_ptr<Entity> weak; // does not hold on to the obj after internal scope killed ---> when internal scope exits, obj destroyed.
        {
        // creating a shared ptr
        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Entity> shared_e = std::make_shared<Entity>();
        std::shared_ptr<Entity> e_scopeout = shared_e; // will ensure that the entity created inside this scope does not die in the next line as the e_scopeout is holding a reference to the object created within this subscope

        weak = shared_e; // this will not preserve the object out of this internal scope
        }
        // the entity from inside the nested scope is still maintained as the e_scopeout was assigned to the object created inside the scope
    }
    // here is when the object actually dies since the shared ptr e_scopeout was freed when the stack frame collapsed.

    return 0;
}

