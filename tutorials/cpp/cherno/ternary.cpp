// ternary operators ---> (condition ? true case: false case )
#include <iostream>
#include <string>

static int s_thrust = 10;
static int s_fuel = 75;

int main()
{
    if (s_fuel > 50)
    {
        s_thrust = 90;
    }
    else
    {
        s_thrust = 40;
    }

    std::cout << s_thrust << '\n';
    
    s_thrust = (s_fuel > 50 ? 90 : 40);  

    // faster string assignment as no empty intermediate string object created pre value assignment.
    std::string status = s_fuel > 50 ? "Nominal" : "Anomaly";

    // std::string status; // temporary empty string object created
    // if (s_fuel > 50)
    // {
    //     status = "nominal";
    // }
    // else
    // {
    //     status = "anomaly";
    // }

    // nesting ternary operators

    s_thrust = s_fuel > 50 ? s_fuel > 70 ? 100 : 70 : 40;
    // if fuel > 70 then set thrust to 100, if fuel > 50 set thrust to 70 else 50  
    std::cout << s_thrust << '\n'; // should set thrust to 100

    s_thrust = s_fuel > 50 && s_fuel < 110 ? s_fuel > 70 ? 100 : 70 : 40;
    // operator precedencewould encapsulate the first condition with the and condition during evaluation so this statement would be evaluated as:
    //    s_thrust = ( s_fuel > 50 && s_fuel < 110 ) ? s_fuel > 70 ? 100 : 70 : 40;
    
    return 0;
}

