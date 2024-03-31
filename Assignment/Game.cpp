#include "Game.h"
#include "GameTitle.h"
#include <iostream>
#include <string>
#include "Choice.h" 
#include "ItemManager.h"

void Game::Run()
{
    ItemManager item; // Initialize ItemManager instance
    PrintCurrentInfo();
    while (true) {
        if (!HandleCommand(item.getPlayerBalance()))
            break;
    }
}

void Game::PrintCurrentInfo()
{
    ItemManager item;
    std::cout << DEADLY_CORP_TITLE;
    std::cout << "\nWelcome\nWe trust you will be a great asset to the company!\n";
    std::cout << "\n================ DAY " << m_currentDay << " ================\n";
    std::cout << "Current cargo value : $" << m_m << "\n";
    std::cout << "Current balance: $" << item.getPlayerBalance() << "\n"; // Access player balance through item
    std::cout << "Current quota: $" << m_quota << " (3 days left to meet quota)\n";
    std::cout << "Currently orbiting: " << m_planet << "\n";
    std::cout << "\n>MOONS\nTo see the list of moons the autopilot can route to.\n";
    std::cout << "\n>STORE\nTo see the company store's selection of useful items.\n";
    std::cout << "\nINVENTORY\nTo see the list of items you've already bought.\n";
    std::cout << "\nEXIT\nTo exit game.\n";
    std::cout << "\n";
}

bool Game::HandleCommand(int& playerBalance) {
    std::string x;
    std::cout << ">";
    std::cin >> x;
    std::cout << x;


    ItemManager item; // Initialize ItemManager instance
    auto choice = ConvertStringToChoice(x);
    auto buy = ConvertStringToChoice(x);

    switch (choice) {
    case Choice::Moons:
        std::cout << "\nWelcome to the exomoons catalogue.\nTo route the autopilot to a moon, use the word ROUTE.\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "\n* Corporation\n* Prototyping\n* Insurance\n* Pledge\n* Defence\n";
        break;
    case Choice::Store:
        std::cout << "\nWelcome to the Corporation store.\nUse the word BUY on any item.\n";
        std::cout << "---------------------------------------------\n";
        item.displayStore();
        std::cout << "\nBalance: $" << item.getPlayerBalance() << "\n";
        break;
    case Choice::Inventory:
        std::cout << "\nThe following items are available.\n";
        std::cout << "---------------------------------------------\n";
        item.displayInventory();
        break;
    case Choice::Exit:
        std::cout << "\n---------------------------------------------------\n";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<<<<<<<<\n";
        std::cout << "\n---------------------------------------------------\n";
        return false;
    case Choice::Unknown:
        std::cout << "\nINVALID COMMAND\n";
        break;
    case StoreItem::Flashlight:
        item.buyItem(StoreItem::Flashlight, playerBalance);
        break;
    case StoreItem::Shovel:
        // Handle Shovel case
        break;
    case StoreItem::ProFlashlight:
        // Handle ProFlashlight case
        break;
    case StoreItem::Teleporter:
        // Handle Teleporter case
        break;
    case StoreItem::InverseTeleporter:
        // Handle InverseTeleporter case
        break;
    case StoreItem::Backpack:
        // Handle Backpack case
        break;
    case StoreItem::HydraulicsMk2:
        // Handle HydraulicsMk2 case
        break;
    }
    return true;
}