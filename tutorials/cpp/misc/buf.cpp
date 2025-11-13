// copying large resources

#include <iostream>

class Buffer{
    public:
        Buffer(size_t size) : m_size(size), data(new int[size]) {}
        ~Buffer() 
        {
            delete[] data;
        }
    private:
        size_t m_size;  
        int* data;

};

int main()
{
    Buffer buff(1000);
    Buffer cpy = buff; // underfined behavior --> dangling ptr or double delete

    return 0;
}

