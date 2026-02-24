#include <iostream>
#include <map>

int main(void)
{   
    std::map<int, std::string> hashmap;

    hashmap[1] = "Batman";
    hashmap[2] = "Joker";
    hashmap[3] = "Riddler";
    hashmap[4] = "Scarecrow";

    std::cout << "map elements: \n";
    for (auto &entry : hashmap)
    {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }

    return EXIT_SUCCESS;
}