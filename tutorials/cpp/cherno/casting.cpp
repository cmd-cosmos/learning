// type casting ---> C style vs C++ style casting 
// implicit and explicit conversion

#include <iostream>
#include <string>

void println(const auto string)
{
    std::cout << string << '\n';
}

class Base
{
  public:
    Base() { println("Base Constructor");};
    ~Base() { println("Base Destructor");};
};

class Derived : public Base
{
  public:
    Derived() { println("Derived Constructor");};
    ~Derived() { println("Derived Destructor");};
};

class ClassClass : public Base
{
  public:
    ClassClass() { println("ClassClass Constructor");};
    ~ClassClass() { println("ClassClass Destructor");};
};

int main()
{
    int a = 5;
    double val = a; // implicit casting of a from int to double
    double b = 3.14;
    int val2 = b; // implicit cast from double to int
    // C style casting ---> passing data type in () for explicit casting 
    int val3 = (int) b; // explicit cast from double to int

    // C++ style cast ---> 4 major casts ---> static, reinterpret, const, dynamic casts
    // some additional checks by the compiler at compile time
    // all cpp style casts are sort of syntactic sugar over c type casts, no difference in terms of functions except for compile time checks
    double s = static_cast<int>(val); // cast a double to an int
    
    println(a);

    Derived* derived = new Derived();
    Base* base = derived;
    ClassClass* cc = dynamic_cast<ClassClass*>(base); // cc is nothing but an instance of the derived class as the base pointer points to the derived object
    // a static cast or C style cast would not raise errors but dynamic cast will let us know of this error

    // using the dynamic cast we can confirm if base is an instance of the derived class or not.
    // output
    //cannot 'dynamic_cast' 'base' (of type 'class Base*') to type 'class ClassClass*' (source type is not polymorphic)

    return 0;
}
