#include "MoonManager.h"
#include <iostream>

void MoonManager::registerMoon(AbstractMoon* moon) {
    moons.push_back(moon);
}

void MoonManager::printMoons() {
    std::cout << "\n";
    for (int i = 0; i < moons.size(); ++i) {
        std::cout << i + 1 << "* " << moons[i]->name() << "\n";
    }
}

void MoonManager::routeToMoon(int moonIndex) {
    if (moonIndex >= 1 && moonIndex <= moons.size()) {
        std::cout << "Routing to " << moons[moonIndex - 1]->name() << "\n";
        

    }
    else {
        std::cout << "Invalid moon name.\n";
    }
}
