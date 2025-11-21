// virtual functions in classes

#include <iostream>

class Shape{
    public:
        virtual void calc()
        {
            std::cout << "Generic Area = 0\n";
        }
        virtual ~Shape()
        {
            std::cout << "base destructor called\n";
        }
};

class Square : public Shape{
    private:
        int m_edge, m_area;
    public:
        Square(int edge) : m_edge{edge} {}
        
        void calc() override{
            this->m_area = this->m_edge*this->m_edge;
            std::cout << "area of square = " << this->m_area << "\n"; 
        }
        
        ~Square() {
            std::cout << "Square destructor.\n";
        }
};

int main()
{
    {
        Shape general;
    }
    {
        int edge = 3;
        Square sq{edge};
        sq.calc();
    }
    return 0;
}