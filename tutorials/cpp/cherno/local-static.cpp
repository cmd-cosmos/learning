// local scope context of the static keyword
// considerations made during var declaration --> lifetime and scope
// lifetime ---> how long will the var remain in memory before deletion
// scope ---> where we can access that var
// static local variable ---> allows for declaring a variable with a lifetime of the entire program while the scope is limited to be inside that function or scope.

#include <iostream>
#include <string>

// this would produce same behavior as local static BUT... this i can be modified from any scope, I could set it to 10 in the main scope and if i run an increment function, it will add 1 to the newly assigned 10 instead of to 0
// int i = 0;

void Bar()
{
    // since no static used for i ---> on each function call the val will be inti to 0, so the output will be 1 prinitng as many times as the function 
    int i = 0;
    i++;
    std::cout << i << std::endl;
}

void Foo()
{
    // since static used ---> val of i persists even after frame collapses and thus if foo called 5 times we get 1 to 5 printed to console
    // i is not visible to the global scope, only to the function
    static int i = 0;
    i++; 
    std::cout << i << '\n';
}


// use case
class Singleton
// only 1 instance in existance
{
private:
    static Singleton* s_Instance;
public:
    static Singleton& Get() { return *s_Instance; }
    void func() {}
};
// ensures a single instance of the singleton class used throughout the scope
Singleton* Singleton::s_Instance = nullptr;

class Singleton2
// simpler version using the static keyword
{
public:
    static Singleton2& Get()
    { 
        static Singleton2 instance;
        return instance;
    }
    void clean() {}
};


int main()
{
    Bar();
    Bar();
    Bar();
    Bar();
    Bar();


    Foo();
    Foo();
    Foo();
    Foo();
    Foo();
    Foo();

    Singleton::Get().func();

    // using static in local scope for classes to create a singleton instance instead of the other complex implementation
    Singleton2::Get().clean();

    return 0;
}

