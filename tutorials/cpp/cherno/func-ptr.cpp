// raw function pointers ---> from C implementation
// using functions to directly assign values to variables

#include <iostream>
#include <string>
#include <vector>

void Print()
{
    std::cout << "I am Batman." << '\n';
}

void Val(int a)
{
    std::cout << a << '\n';
}

void PrintString(const std::string& str)
{
    std::cout << str << '\n';
}

void ForEach(const std::vector<std::string>& vec, void(* printString_ptr)(const std::string&))
{
    for (std::string inp : vec)
    {
        printString_ptr(inp);
    }
}

int main()
{
    Print();

    // this evaluates to auto func = &Print
    auto func = Print; //this returns a function pointer ---> we cannot call this function like this -> Print() as the function has void return --->function name implicitly converted to &Print ---> and address to the function instruction block in memory retrieved
    
    func(); // now we can the variable as a function

    // alternate syntax for function pointers
    void (*func2)() = Print;

    typedef void(*funct_ptr)(); // func_ptr() <--- empty bracket is for parameter passing
    funct_ptr func3 = Print;
    func3();

    // for taking an argument
    typedef void(* val_ptr)(int);
    val_ptr val_func = Val;
    val_func(5);
    val_func(6);
    val_func(7);
    val_func(0);

    std::vector<std::string> vec = {"Batman", "Alfred", "Robin", "Nighwing", "Joker"};

    // creating a for each loop to iterate through the vector
    ForEach(vec, PrintString);
    // we could use lambda as it is a throwaway func.

    return 0;
}

