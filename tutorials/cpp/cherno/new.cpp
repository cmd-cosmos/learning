// new ---> allocate memory on the heap
// comparitively longer process for allocation
/*
1. write new with the datatype
2. based on mentioned datatype --> size of alloc calc in bytes, eg) (int: 4 bytes)
3. new requests the C std lib for the x amt (4 bytes in case of int example) of mem
4. looks for 4 contiguous bytes in mem --> a block of 4 bytes 
5. return ptr to that address where 4 contiguous bytes can be allocated
6. we can get read/write address to those 4 contiguous locations starting from the ptr address

---> does not literally search for 4 empty contiguous locations
---> a free list maintains addresses that have bytes free
---> well optimized process but yet quite slow as the 5 step process followed for each new declarations
*/

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}
    const String& GetName() const { return m_Name;}
};

int main()
{
    int a = 2; // stack mem

    int* b = new int; // 4bytes of heap mem --> since new returns a ptr we declare b as a ptr 
    int* c = new int[50]; // 200 bytes allocated starting from address of c

    // all 10 entities will be in a row
    Entity* e = new Entity[10]; // returns space for 10 entity objects

    // deleting is essential once memory not needed
    delete b;
    delete[] c; // the array operator must be called during free too ---> []
    delete e;

    // placement new is used for optimization ---> we can use preexisting unused memory to allocate something instead of finding a completely new location

    return 0;
}