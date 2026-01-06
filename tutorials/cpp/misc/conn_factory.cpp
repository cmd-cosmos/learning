#include <iostream>
#include <memory>

struct DB
{
    DB() {
        std::cout << "DB conn opened\n";
    }
    ~DB() {
        std::cout << "DB conn closed\n";
    }

    void query() {
        std::cout << "QUERY: SELECT FLIGHT_ID FROM ROCKETS\n";
    }
};

std::unique_ptr<DB> openDB(bool fail) {
    if (fail) return nullptr;
    return std::make_unique<DB>();
}


int main(void) {
    auto db = openDB(false);
    if (!db) {
        return 0;
    }
    db->query();

    return EXIT_SUCCESS;
}