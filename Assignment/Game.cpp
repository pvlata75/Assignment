#include "Game.h"
#include "GameTitle.h"
#include <iostream>
#include <string>
#include "Choice.h" 
#include "StoreItem.h"
#include "Util.h"
#include "AbstractMoon.h"
#include "MoonManager.h"
#include "Moon.h"
#include "StoreMoon.h"


void Game::Run()
{
    Register();
    PrintCurrentInfo();
    SetPhase(Phase::Orbiting);

    while (true) {
        if (!HandleCommand()) {
            continue;
        }

        if (m_currentPhase == Phase::Orbiting) {
            m_currentMoon = m_moonManager.GetMoon("Corporation");
        }

    }
}

void Game::Register()
{
    m_itemManager.RegisterItem(StoreItem::Flashlight, "Flashlight", 60);
    m_itemManager.RegisterItem(StoreItem::Shovel, "Shovel", 100);
    m_itemManager.RegisterItem(StoreItem::ProFlashlight, "ProFlashlight", 200);
    m_itemManager.RegisterItem(StoreItem::Teleporter, "Teleporter", 300);
    m_itemManager.RegisterItem(StoreItem::InverseTeleporter, "InverseTeleporter", 400);
    m_itemManager.RegisterItem(StoreItem::Backpack, "Backpack", 500);
    m_itemManager.RegisterItem(StoreItem::HydraulicsMk2, "HydraulicsMk2", 1000);  

    // Register Moons
    m_moonManager.RegisterMoon(StoreMoon::Corporation, "Corporation", 0, 0, 0, 1);
    m_moonManager.RegisterMoon(StoreMoon::Prototyping, "Prototyping", 0, 3, 30, 0.5);
    m_moonManager.RegisterMoon(StoreMoon::Insurance, "Insurance", 0, 30, 50, 0.45);
    m_moonManager.RegisterMoon(StoreMoon::Pledge, "Pledge", 0, 30, 50, 0.4);
    m_moonManager.RegisterMoon(StoreMoon::Defence, "Defence", 0, 10, 70, 0.35);
    m_moonManager.RegisterMoon(StoreMoon::Mars, "Mars", 100, 60, 80, 0.3);
    m_moonManager.RegisterMoon(StoreMoon::Venus, "Venus", 200, 70, 90, 0.25);
}

void Game::PrintMoonInfo()
{
    std::cout << "Welcome to " << m_currentMoon->GetName() << " !" << std::endl;
    std::cout << "Current cargo value : $" << m_total << std::endl;
    std::cout << "Current balance : $" << m_balance << std::endl;
    std::cout << "Current quota : $" << m_quota << " (" << 3 - m_currentDay << " days left to meet quota)" << std::endl;
    std::cout << "Number of employees : " << m_employees << std::endl;
}

int Game::GetBalance() const
{
    return m_balance;
}

std::string Game::GetCurrentMoon()
{
    return m_currentMoonName;
}

void Game::SetCurrentMoon(std::string moonName)
{
    m_currentMoonName = moonName;
}


void Game::UpdateBalance(int a)
{
    m_balance += a;
}

void Game::SetMoon(AbstractMoon* moon)
{
    m_currentMoon = moon;
}

void Game::SetPhase(Phase phase)
{
    m_currentPhase = phase;
}

void Game::UpdateValue(int a)
{
    m_total = a;
}

int Game::GetNumEmployees() const
{
    return m_employees;
}

void Game::SetEmployees(int employees)
{
    m_employees = employees;
}

bool Game::ExitGame()
{
    return false;
}

void Game::StartNewCycle()
{
}

void Game::GameOver()
{
}

void Game::Leave()
{
    m_currentPhase = Phase::Orbiting;
   
    for (auto& moon : m_moonManager.GetMoon(m_currentMoonName)) {
        moon->OnDayBegin(*this);
    }
    

    if (m_currentDay == 5) {
        if (m_balance >= m_quota) {
            m_cycleDay = 1;
            m_currentDay++;
            m_quota = m_quota * 0.5 + m_quota;
            PrintCurrentInfo();
        }
        else {
            GameOver();
        }
    }
    else {
        m_cycleDay++;
        m_currentDay++;
        PrintCurrentInfo();
    }
}


void Game::Land()
{
    SetPhase(Phase::Landing);
    PrintMoonInfo();

    if (m_currentMoon->GetName() == "Corporation") {
        std::cout << "Type SELL to sell your cargo contents and increase your balance and achieve quota.\n";
        std::cout << "Specify the amount to sell after the SELL word to only sell a portion of your cargo.\n";
        std::cout << "Type LEAVE to leave the planet.\n";
    }
    else {
        std::cout << "Type SEND followed by the number of employees you wish to send inside the facility.\n";
        std::cout << "All the other employees will stay on the ship.\n";
        std::cout << "Type LEAVE to leave the planet.\n";
    }

    while (m_employees > 0 && !m_exitGame) {

        std::string x;
        std::cout << ">";
        std::getline(std::cin, x);
        std::vector<std::string> arguments;
        Util::lower(x);
        Util::splitArguments(x, arguments);

        if (arguments.size() > 0 && x == "buy" || x == "route") {
            auto buy = ConvertStringToStoreItem(arguments[0]);
            if (buy == StoreItem::Invalid) {
                std::cout << "This command is not available at this time.\n";
            }
            else {
                m_itemManager.BuyItem(buy, m_balance);
            }
            auto route = ConvertStringToStoreMoon(arguments[0]);
            if (route == StoreMoon::Invalid) {
                std::cout << "This command is not available at this time.";
            }
            else {
                m_moonManager.RouteToMoon(*this, arguments[0]);
            }
        }

        if (x == "inventory") {
            m_itemManager.DisplayInventory();
        }
        else if (x == "store") {
            m_itemManager.DisplayStore();
        }
        else if (x == "moons") {
            m_moonManager.PrintMoons();
        }
        else if (x == "route") {
            std::cout << "This command is not available at this time.\n";
        }
        else if (x == "leave") {
            Leave();
            break;
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }
}


void Game::PrintCurrentInfo()
{
    ItemManager item;
    std::cout << DEADLY_CORP_TITLE;
    std::cout << "\nWelcome\nWe trust you will be a great asset to the company!\n";
    std::cout << "\n================ DAY " << m_currentDay << " ================\n";
    std::cout << "Current cargo value : $" << m_total << "\n";
    std::cout << "Current balance: $" << m_balance << "\n"; 
    std::cout << "Current quota: $" << m_quota << " (3 days left to meet quota)\n";
    switch(m_currentPhase) {
        case Phase::Orbiting:
            std::cout << "Currently orbiting: " << m_currentMoon->GetName() << "\n";
            break;
    }
    std::cout << "\n>MOONS\nTo see the list of moons the autopilot can route to.\n";
    std::cout << "\n>STORE\nTo see the company store's selection of useful items.\n";
    std::cout << "\nINVENTORY\nTo see the list of items you've already bought.\n";
    std::cout << "\nEXIT\nTo exit game.\n";
    std::cout << "\n";
}



bool Game::HandleCommand() {
    std::string x;
    std::cout << ">";
    std::getline(std::cin, x);
    std::vector<std::string> arguments;
    Util::lower(x);
    Util::splitArguments(x, arguments);

    if (arguments.size() > 0 && x == "buy" || x == "route") {
        auto buy = ConvertStringToStoreItem(arguments[0]);
        if (buy == StoreItem::Invalid) {
            std::cout << "This command is not available at this time.";
        }
        else {
            m_itemManager.BuyItem(buy, m_balance);
        }

        auto route = ConvertStringToStoreMoon(arguments[0]);
        if (route == StoreMoon::Invalid) {
            std::cout << "This command is not available at this time.";
        }
        else {
            m_moonManager.RouteToMoon(*this, arguments[0]);
        }
        return true;
    }

    auto choice = ConvertStringToChoice(x);

    switch (choice) {
    case Choice::Moons:
        m_moonManager.PrintMoons();
        return true;
    case Choice::Store:
        m_itemManager.DisplayStore();
        std::cout << "\nBalance: $" << GetBalance() << "\n";
        return true;
    case Choice::Inventory:
        m_itemManager.DisplayInventory();
        return true;
    case Choice::Exit:
        std::cout << "\n---------------------------------------------------\n";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<<<<<<<<\n";
        std::cout << "\n---------------------------------------------------\n";
        return false;
    }
}



