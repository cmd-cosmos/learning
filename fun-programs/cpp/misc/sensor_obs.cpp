#include <iostream>
#include <memory>

struct Sensor {
    int val = 100;
};

int main(void) {
    auto sensor = std::make_shared<Sensor>();
    std::weak_ptr<Sensor> uiView = sensor;

    // drops the last owning ref
    // sensor obj destroyed immediately
    sensor.reset();

    if (auto s = uiView.lock()) {
        std::cout << s->val << "\n";
    }
    else {
        std::cout << "sensor offline\n";
    }

    return EXIT_SUCCESS;
}