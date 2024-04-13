#ifndef GAME_H
#define GAME_H

#include <string>
#include "ItemManager.h"
#include "Choice.h"
#include "AbstractMoon.h"
#include "MoonManager.h"
#include "Moon.h"

enum class Phase {
    Orbiting,
    Landing
};

class Game {
public:
    void Run();

    void Register();

    int GetBalance() const;

    void SetCurrentMoon(std::string moonName);

    std::string GetCurrentMoon();

    int GetNumEmployees() const;

    void PrintCurrentInfo();

    void PrintMoonInfo();

    bool HandleCommand();

    void UpdateBalance(int a);

    void SetMoon(AbstractMoon*);

    void SetPhase(Phase);

    void UpdateValue(int a);

    void SetEmployees(int employees);

    bool ExitGame();

    void Leave();
    
    void StartNewCycle();

    void GameOver();

    void Land();

private:
    ItemManager m_itemManager;
    MoonManager m_moonManager;
    AbstractMoon* m_currentMoon;
    std::string m_currentMoonName;
    Choice m_currentChoice;
    Phase m_currentPhase;
    int m_cycleDay;
    int m_employees = 4;
    int m_balance = 5000;
    int m_currentDay = 1;
    int m_total;
    int m_quota = 150;
    bool m_exitGame;
};

#endif // GAME_H
