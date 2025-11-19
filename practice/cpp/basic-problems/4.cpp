// leap year check

#include <iostream>

int main()
{
    int year;
    std::cout << "Enter Year: "; // insert the text in the cout stream
    std::cin >> year; // year will extract a val from the input stream

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        std::cout << "Leap Year.\n";
    }
    else
    {
        std::cout << "Not a Leap Year.\n";
    }

    // using ternary operators
    (year % 4 == 0 && year % 100 != 0) ? std::cout << "Leap Year." : ((year % 400 == 0) ? std::cout << "Leap Year" : std::cout << "Not a Leap Year.");
    
    return EXIT_SUCCESS;
}