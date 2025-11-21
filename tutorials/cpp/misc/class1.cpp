// working with a sample class

#include <iostream>

class Car
{
    private:
        int modelNum;
        int numDoors;
        std::string name;
        bool isPreowned;
        bool isElectric;

    public:
        Car(std::string nameInp, int modelNumInp, int numDoorsInp, bool isPreownedInp, bool isElectricInp) :
        modelNum{modelNumInp}, numDoors{numDoorsInp}, name{nameInp}, isPreowned{isPreownedInp}, isElectric{isElectricInp}   
        {
            std::cout << "Constructed Car Obj with following parameters: \n";
            std::cout << "Name: " << this->name << '\n';
            std::cout << "Model Num: " << this->modelNum << '\n';
            std::cout << "Num Doors: " << this->numDoors << '\n';
            std::cout << "isPreowned: " << this->isPreowned << '\n';
            std::cout << "isElectric: " << this->isElectric << '\n';
        }

        ~Car(){}
};


int main()
{
    Car car{
        "Civic",
        123,
        4,
        true,
        false
    };

    return 0;
}