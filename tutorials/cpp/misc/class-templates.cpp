// class templates --> similar to function templates but for class overloads
// https://www.youtube.com/watch?v=mQqzP9EWu58

#include <iostream>
#include <string>
#include <vector>

class Base
{
    private:
        int m_X;
        int m_Y;

    public:
        Base(int x, int y) : m_X(x), m_Y(y)
        {
            std::cout << "Base Constructor.\n";
        };
        ~Base()
        {
            std::cout << "Base Destructor.\n";
        };

};

int main()
{
    return 0;
}
