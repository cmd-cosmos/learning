// ALWAYS PASS OBJECTS BY CONST REFERENCE UNLESS MODS REQUIRED/ COPY OPERATION REQUIRED. 

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

        char& operator[](unsigned int index)
        {
            return m_Buffer[index]; // no bounds checking included
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);

         // copy cosntructor ---> performs a memcpy for the other string 
        String(const String& other) : m_Size(other.m_Size)
        {
            // deep copy
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size+1);
            std::cout << "Deep Copy Performed" << std::endl;
        }

        ~String()
        {
            delete[] m_Buffer; // addressing the mem leak if mem not freed.
        }
};

void Print(const String& string) 
// if we do not pass the string by reference, it will perform the copy function on every Print call for string objects in the main function like s1 and s2
{
    std::cout << string << std::endl;
}

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

    // copy operation on the current string class will fail
    // it will cause problems as the pointer for the copied string will share the same member vars and thus will call free twice on the same block of mem as both ptrs will pt to the same location.
    String s1 = "Joker";
    String s2 = s1;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    s2[1] = 'i';                    // operator overload required
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    Print(s1);
    Print(s2);
    /*
    Output:

    Joker
    Joker
    Jiker
    Jiker

    Output after a valid copy constructor:

    Batman
    Joker
    Joker
    Joker
    Jiker
    */

    // solution ---> when copying ---> create a new mem block for the copied string to avoid these shallow copy associated mem problems.
    // we use a copy contructor to address this issue
    // it is a constructor that gets called for the second string when it is copied.
    // assignes new mem block to the copied string.

    return 0;
}

/*
What the copy constructor does is

these are shallow copies:

String(const String& other)
{
    memcpy(this, &other, sizeof(String))
}

or 

String(const String& other) : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
{

}

*/