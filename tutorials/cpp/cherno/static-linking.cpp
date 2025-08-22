// using libraries with cpp
// static and dynamically linked libraries 
// statc library ---> when lib is inside the exe file
// dynamic library ---> linked at runtime
// dll file ---> dynamically linked library file which is created with the launch of the application
// static linking should be preferred whenever possible --> also speeds up exe a bit as compiler can apply some link time optimizations

// working with the GLFW openGL library
// .dll.lib files in the GLFw lib-vc2022 folder contain symbol and function locations to the .dll file if dynamically linked

// .lib ---> static lib binary

// #include "GLFW/glfw3.h" // quotes ---> check the relative path(main.cpp path) first and then look in the compiler include paths
// or
#include <iostream>
#include <GLFW/glfw3.h> 
// angular brackets: indicate it is external 

extern "C" int glfwInit();

int main()
{
    int a = glfwInit(); // external symbol missing
    // linker cannot find the library
    return 0;
}

// add linker and compiler flags during compilation to include the library




