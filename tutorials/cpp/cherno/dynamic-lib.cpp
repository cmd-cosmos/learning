// dynamic linking happens at run time
// less or no optimization as dynamic link lib is linked when exe launched
//executable can know that it needs the dll but it does not need to, it could have dependencies on the dll that are coded in the binary or they could be ignored in the exe. 

#include <iostream>
#include <GLFW/glfw3.h> 

int main()
{
    int a = glfwInit(); 
    return 0;
}
