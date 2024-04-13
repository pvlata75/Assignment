#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H

#include <string>



enum class MoonWeather {
    Clear = 0,
    Flooded,
    Eclipsed,
    Stormy,
    Count
};

class Game;

class AbstractMoon {
protected:
    std::string moonName;
    MoonWeather weather;
    int cost;
    int minScrap;
    int maxScrap;
    double explorerBaseSurvival;
    const int baseCargo = 5;

public:

    AbstractMoon(const std::string name, int cost, int minScrap, int maxScrap, double explorerBaseSurvival);
    virtual ~AbstractMoon();

    std::string GetName() const;

    int GetRandomScrap(int min, int max);

    double GetRandomChance();

    virtual void OnDayBegin(Game g);

    virtual void SellCargo(Game g, int amount);
    
    virtual void SendEmployee(Game g, int numExplorers);
    
    std::string GetWeather();

    int GetCost() const;

};


#endif // ABSTRACTMOON_H