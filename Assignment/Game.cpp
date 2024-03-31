#include "Game.h"
#include "GameTitle.h"
#include <iostream>
#include <string>
#include "Choice.h" 
#include "Choice.cpp"

void Game::Run()
{
    PrintCurrentInfo();
    while (true) {
        if (!HandleCommand())
            break;
    }
}

void Game::PrintCurrentInfo()
{
    std::cout << DEADLY_CORP_TITLE;
    std::cout << "\nWelcome\nWe trust you will be a great asset to the company!\n";
    std::cout << "\n================ DAY " << m_currentDay << " ================\n";
    std::cout << "Current cargo value : $" << m_m << "\n";
    std::cout << "Current balance: $" << m_b << "\n";
    std::cout << "Current quota: $" << m_quota << " (3 days left to meet quota)\n";
    std::cout << "Currently orbiting: " << m_planet << "\n";
    std::cout << "\n>MOONS\nTo see the list of moons the autopilot can route to.\n";
    std::cout << "\n>STORE\nTo see the company store's selection of useful items.\n";
    std::cout << "\nINVENTORY\nTo see the list of items you've already bought.\n";
    std::cout << "\nEXIT\nTo exit game.\n";
    std::cout << "\n";
}

bool Game::HandleCommand() {
    std::string x;
    std::cout << ">";
    std::cin >> x;
    std::cout << "\n" << x;

    auto choice = ConvertStringToChoice(x);

    switch (choice) {
    case Choice::Moons:
        std::cout << "\nWelcome to the exomoons catalogue.\nTo route the autopilot to a moon, use the word ROUTE.\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "\n* Corporation\n* Prototyping\n* Insurance\n* Pledge\n* Defence\n";
        break;
    case Choice::Store:
        std::cout << "\nWelcome to the Corporation store.\nUse the word BUY on any item.\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "\n* Flashlight // Price : $60";
        std::cout << "\n* Shovel // Price : $100";
        std::cout << "\n* Pro-flashlight // Price : $200";
        std::cout << "\n* Teleporter // Price : $300";
        std::cout << "\n* Inverse-teleporter // Price : $400";
        std::cout << "\n* Backpack // Price : $500";
        std::cout << "\n* Hydaulics-Mk2 // Price : $1000\n";
        std::cout << "\nBalance: $" << m_b << "\n";
        break;
    case Choice::Inventory:
        std::cout << "\nThe following items are available.\n";
        std::cout << "---------------------------------------------\n";
        break;
    case Choice::Exit:
        std::cout << "\n---------------------------------------------------\n";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<<<<<<<<\n";
        std::cout << "\n---------------------------------------------------\n";
        return false;
    case Choice::Unknown:
        std::cout << "INVALID COMMAND";
        break;
    }

    return true;
}

Choice ConvertStringToChoice(const std::string& input)
{
    std::string lowercase = toLowerAndRemoveSpaces(input);

    if (lowercase == "moons")
        return Choice::Moons;
    else if (lowercase == "store")
        return Choice::Store;
    else if (lowercase == "inventory")
        return Choice::Inventory;
    else if (lowercase == "exit")
        return Choice::Exit;
    else
        return Choice::Unknown; // Handle invalid input
}
