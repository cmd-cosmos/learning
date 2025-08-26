// stack vs heap memory
// when app loads ---> load the program in memory and allocate physical RAM so that the app can run.
// stack and heap are 2 areas in the RAM
// stack ---> fixed area usually 2 MB
// heap ----> predefined but can grow as the app exe.
// both are stored in the RAM, however the stack is usually hot in the cache during the program exe.
// we are allowed to store data in stack/heap.
// stacks are contiguous and stack pointer just moves around based on the size of allocation and stack growth is dependent on the endianness of the machine.
// stack allocation is very fast as stack pointer tracks mem blocks and single cpu instruction to assign new block.

#include <iostream>
#include <memory>

struct Test
{
    float x,y,z;
};

int main()
{
    int stack_val = 10; // initialize variable on the stack
    int stack_array[5]; // array on the stack
    stack_array[0] = 1;
    stack_array[1] = 11;
    stack_array[2] = 111;
    stack_array[3] = 1111;
    stack_array[4] = 11111;
    Test t; // struct obj on the stack
    t.x = 13;
    t.y = 12;
    t.z = 21;
    std::cout << "Stack Allocs:" << std::endl;
    std::cout << stack_val << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout << stack_array[i] << std::endl;
    }
    std::cout << t.x << ',' << t.y << ',' << t.z << std::endl;


    int* heap_val = new int; // requesting for 4 bytes on the heap
    *heap_val = 10; // assigning value to the heap var
    int* heap_arr = new int[5]; // pointer to idx 0 of 5 reserved locn for a 5 int holding array 
    heap_arr[0] = 1;
    heap_arr[1] = 11;
    heap_arr[2] = 111;
    heap_arr[3] = 1111;
    heap_arr[4] = 11111;
    Test* heap_t = new Test; // ptr to a Test object on the heap
    heap_t->x = 1;
    heap_t->y = 2;
    heap_t->z = 3;
    std::cout << "Heap Allocs:" << std::endl;
    std::cout << *heap_val << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout << heap_arr[i] << std::endl;
    }
    std::cout << heap_t->x << ',' << heap_t->y << ',' << heap_t->z << std::endl;

    return 0;
}