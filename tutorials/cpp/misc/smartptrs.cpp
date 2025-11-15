// using smart ptrs --> unique ptrs and shared ptrs 


#include <memory>
#include <iostream>

class Foo{
    public:
        Foo() {
            std::cout << "Foo obj created\n";
        }
        ~Foo() {
            std::cout << "Foo killed\n";
        }
};

int main()
{
    // unique ptrs ensure exclusive ownership until moved
    // automatic mem management
    std::unique_ptr<int> p = std::make_unique<int>(100);
    std::cout << *p << '\n';

    // std::unique_ptr<int> dupli = p; // does not allow copying
    std::unique_ptr<int> mover = std::move(p); // move ownership to the mover ptr

    auto ptr = std::make_unique<Foo>();

    return 0;
}
