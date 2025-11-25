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
            count = 0;
        }

        void countUp()
        {
           count++;
        }

        void printCount()
        {
            std::cout << "Count for Counter " << m_id << ": " << count << '\n';
        }

        void countUpOtherObj(Counter& other)
        {
            other.countUp();
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
    
    c1->countUp();
    c1->countUp();
    c1->countUp();
    
    c1->printCount();
    delete c1;

    Counter* c2 = new Counter(2);

    c2->countUp();
    c2->countUp();
    c2->countUp();
    c2->countUp();

    c1->countUpOtherObj(*c2);

    c2->printCount();

    return 0;
}