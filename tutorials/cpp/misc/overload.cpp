// operator overloading 

#include <iostream>

class Complex
{
    private:
        float m_real, m_imaginary;
    public:
        Complex(float real=0, float imaginary=0) : m_real{real}, m_imaginary{imaginary}
        {

        } 
        Complex operator+(const Complex& c)
        {
            return Complex(m_real + c.m_real, m_imaginary + c.m_imaginary);
        }

        void display()
        {
            std::cout << m_real << " + " << m_imaginary << "i" << '\n';
        }
};


int main()
{
    Complex* c1 = new Complex(1.0f, 3.14f);
    Complex* c2 = new Complex(10.0f, 10.14f);
    Complex* c3 = new Complex();
    *c3 = *c1 + *c2;

    c3->display();

    return 0;
}


