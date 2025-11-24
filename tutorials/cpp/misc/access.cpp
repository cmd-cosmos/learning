// access modifiers in cpp
// access control depends on the class in which the code resides, not on which obj is accessed

#include <iostream>

class Counter{
    private:
        int count;
        int m_id;
    public:
        Counter(int id) : m_id{id}
        {
            std::cout << "Constructing counter obj: " << m_id << '\n';
        }

        ~Counter()
        {
            std::cout << "Destroying counter obj:   " << m_id << '\n';
        }


};

class Foo{
    private: 
        int count;
        int m_id;
    public:
        Foo(int id) : m_id{id}
            {
                std::cout << "Constructing foo obj: " << m_id << '\n';
            }

        ~Foo()
            {
                std::cout << "Destroying foo obj:   " << m_id << '\n';
            }

    };

int main()
{
    Counter* c1 = new Counter(1);
    delete c1;

    return 0;
}