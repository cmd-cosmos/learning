#include <iostream>
#include <map>

void printMap(const auto& hashmap)
{
    for(auto& entry : hashmap)
    {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }
}

int main(void)
{
    std::map<int, std::string> hashmap;

    hashmap[1] = "falcon";
    hashmap[2] = "starship";
    hashmap[3] = "vulcan";
    hashmap[4] = "proton";
    
    printMap(hashmap);
    std::cout << std::boolalpha;

    std::cout << "hashmap contains key=1: " << hashmap.contains(1) << std::endl;

    hashmap.insert(std::map<int, std::string>::value_type(5, "electron"));
    hashmap.insert(std::map<int, std::string>::value_type(5, "electron"));
    
    printMap(hashmap);

    std::cout << "hashmap.at(3): " << hashmap.at(3) << std::endl;

    std::cout << "hashmap size: " << hashmap.size() << " key val pairs\n";

    return 0;
}