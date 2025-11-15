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

    {
        auto ptr = std::make_unique<Foo>();
    }

    // shared pointers
    {
        std::shared_ptr<int> p1 = std::make_shared<int>(100);
        std::shared_ptr<int> p2 = p1; // shared pointers
        
        std::cout << p1.use_count() << '\n'; // total ptrs sharing similar ownership
        
        std::shared_ptr<Foo> o1 = std::make_shared<Foo>();
        std::cout << o1.use_count() << '\n';
        {
            std::shared_ptr<Foo> o2 = o1;
            std::cout << o1.use_count() << '\n';
        }
        std::cout << o1.use_count() << '\n';
    
    }
    
    // weak pointers
    std::shared_ptr<int> sp = std::make_shared<int>(1);
    std::weak_ptr<int>   wp = sp;

    if (auto locked = wp.lock()){
        std::cout << *locked << '\n';
    }

    sp.reset();

    if (wp.expired()){
        std::cout << "obj killed\n";
    }

    return 0;
}
