#ifndef ABSTRACTMOON_H
#include <string>

enum class MoonWeather {
    Clear = 0,
    Flooded,
    Eclisped,
    Stormy,
    Count 
};

class Game;

class AbstractMoon {
protected:
    std::string moonName;
    MoonWeather weather;

public:

    const std::string name();

    virtual void onDayBegin(Game g);

    virtual void sellCargo(Game g, int amount);

    virtual void sendEmployees(Game g, int count);

    void printWelcomeMessage();
};


#endif // !ABSTRACTMOON_H