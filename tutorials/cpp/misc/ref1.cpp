// refs --> do not occupy memory like a var would
//      --> not a separate object, it is just an alias
//      --> once bound, it cannot be reseated
//      --> cannot be bound to rvalues directly
//      --> bind to lvalues which are named objs or anything with storage

#include <iostream>

int main()
{
    int x = 100;
    int& r = x; // lvalue reference is legal

    std::cout <<  "x = &r, r =" << r << '\n';

    // int& r2 = 2000;    // illegal rvalue reference
    const int& r2 = 2000; // 2000 is materialized as a temp --> it can be used for avoiding copies, func overloading and providing efficient read-only params 
    
    // legal rvalue-only references
    int&& rr = 10; 
    int y = 1;
    // int&& rr2 = y;     // a rvalue ref cannot be bound to an lvalue

    return EXIT_SUCCESS;
}