#include <iostream>
#include <memory>

struct Plugin {
    virtual ~Plugin() = default;
    virtual void run() = 0;
};

struct Audio : Plugin {
    void run() override {
        std::cout << "running audio\n";
    }
};

int main(void)
{
    std::unique_ptr<Plugin> p = std::make_unique<Audio>();
    p->run();

    return EXIT_SUCCESS;
}
