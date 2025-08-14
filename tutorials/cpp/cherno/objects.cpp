// objects creation methods: the choices depend on the source of memory.
// which memory are the objects instantiated in ---> stack or heap
/*
stack objects:
lifespan ---> fixed and dependent on the scope
once out of the scope ---> stack objects are destroyed.
*/ 
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {} // MIL assigns unknown for default constructor 
    Entity(const String& name) : m_Name(name) {} // MIL to assign name to m_Name if passed to the constructor
    const String& GetName() const {return m_Name;}
};

int main()
{ 
    //Stack object creation ---> used most often unless obj req for a scope agnostic lifespan
    // stack also has very limited memory --> 1 MB or 2 MB generally
    Entity stk_entity; // this calls the default constructor
    std::cout << stk_entity.GetName() << '\n';
    
    Entity stk_e("Batman"); // this is the parametrized constructor
    std::cout << stk_e.GetName() << '\n';

    // creating objects of the same class on the heap
    // heap allocation
    Entity* e_heap;
    {
        // different scope
        Entity* ent_heap = new Entity("Joker");
        e_heap = ent_heap;
        std::cout << e_heap->GetName() << '\n';
    }
    // even at this point the name variable assigned to the ent_heap is preserved
    // memory is cleared only when the delete method is called, thus ensuring a longer lifespan.

    delete e_heap;
    
    return 0;
}
