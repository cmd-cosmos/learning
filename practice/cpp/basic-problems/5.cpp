// armstrong nums calc
// armstrong nums --> an int = sum of own digits raised to power of total digits in num
// eg) 1^3 + 5^3 + 3^3 = 153 <--- armstrong num

#include <iostream>
#include <cmath>

int main()
{
    int inp_num, temp, digits=0, check=0;
    std::cout << "Enter Num: ";
    std::cin >> inp_num;
    temp = inp_num;

    // basic algo to count number of digits
    if (inp_num == 0)
    {
        digits = 1;
        std::cout << "It is an Armstrong Num.\n";
        return EXIT_SUCCESS;
    }
    else
    {
        while (inp_num != 0)
            {
                inp_num /= 10;
                digits++;
            }
    }
    
    std::cout << "Total Digits: " << digits << '\n';

    int copy = temp;
    while(temp != 0)
    {
        int digit = temp % 10;
        check += pow(digit, digits);
        temp /= 10;
    }
    std::cout << "Check Val: " << check << '\n';

    if (check == copy)
    {
        std::cout << "Armstrong Number.\n";
    }
    else
    {
        std::cout << "Not Armstrong Number.\n";
    }

    return 0;
}
