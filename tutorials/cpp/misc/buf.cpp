// copying large resources

#include <iostream>
#include <algorithm>

class Buffer{
    public:
        Buffer(size_t size) : m_size(size), data(new int[size]) {}
        ~Buffer() 
        {
            delete[] data;
        }

        // deep copy using the copy constructor
        Buffer(const Buffer& other) : m_size(other.m_size), data(new int[other.m_size])
        {
            std::copy(other.data, other.data+m_size, data);
        }

        Buffer& operator=(const Buffer& other){
            if (this != &other)
            {
                delete[] data;
                m_size = other.m_size;
                data = new int[m_size];
                std::copy(other.data, other.data + m_size, data);
            }
            return *this;
        }

    private:
        size_t m_size;  
        int* data;

};

int main()
{
    Buffer buff(1000);
    Buffer cpy = buff; // deep copy using the copy contructor

    Buffer mv = std::move(buff); // move

    return 0;
}

