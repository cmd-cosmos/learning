#include <iostream>
#include <string>
#include <cstring>

class String
{
    private:
        char* m_Buffer;         // pts to char buffer
        unsigned int m_Size;    // track string size
    public:
        String(const char* string)
        {
            m_Size = strlen(string);         // strlen does not include null term.
            m_Buffer = new char[m_Size + 1]; // null terminator accounted for.
            memcpy(m_Buffer, string, m_Size); // if we use strcpy  ---> includes the \0 char
            // safer option to add null char post memcpy
            m_Buffer[m_Size] = 0;
        }
        friend std::ostream& operator<<(std::ostream& stream, const String& string);
        ~String()
        {
            delete[] m_Buffer; // addressing the mem leak if mem not freed.
        }
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    // when we do not account for the null termination char in the String class
    // output: Batmanⁿ¢5Ñ+┤    <------- garbage incl.
    String string = "Batman"; 
    std::cout << string << std::endl;
}