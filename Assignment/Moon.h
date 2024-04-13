#ifndef MOON_H
#define MOON_H

#include "AbstractMoon.h" 
#include "MoonManager.h"
#include "Game.h" 
#include <iostream>


class Moon : public AbstractMoon {
private:
    int cost;
    int minScrap;
    int maxScrap;
    double explorerBaseSurvival;
    Game game;

public:
    Moon(const std::string name, int cost, int MinScrap, int MaxScrap, double explorerBaseSurvival);

    void OnDayBegin(Game g) override;

    void SellCargo(Game g, int amount) override;

    void SendEmployee(Game g, int numExplorers) override;

    int GetCost() const;
};

#endif // MOON_H
