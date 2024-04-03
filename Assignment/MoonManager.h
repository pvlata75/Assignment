#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include <vector>
#include <string>
#include "AbstractMoon.h"

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;

public:
    void registerMoon(AbstractMoon* moon);

    void printMoons();

    void routeToMoon(int moonIndex);
};

#endif // MOONMANAGER_H
