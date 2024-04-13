#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include <vector>
#include <string>
#include "AbstractMoon.h"
#include "Game.h"  
#include "StoreMoon.h"
#include "Moon.h"


class MoonManager {
private:
    std::map<StoreMoon, std::unique_ptr<Moon>> m_moons;

public:
    void RegisterMoon(StoreMoon moonId, std::string name, int cost, int minScrap, int maxScrap, double explorerBaseSurvival);

    void PrintMoons();

    AbstractMoon* GetMoon(const std::string moonName);

    void RouteToMoon(Game g, const std::string moonName);
};

#endif // MOONMANAGER_H
