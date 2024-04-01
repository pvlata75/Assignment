#include "Game.h"
#include "GameTitle.h"
#include <iostream>
#include <string>
#include "Choice.h" 
#include "StoreItem.h"
#include "Util.h"

void Game::Run()
{
    RegisterItems();
    PrintCurrentInfo();
    while (true) {
        if (!HandleCommand()) {
            return;
        }
    }
}

void Game::RegisterItems()
{
    m_itemManager.RegisterItem(StoreItem::Flashlight, "Flashlight", 60);
    m_itemManager.RegisterItem(StoreItem::Shovel, "Shovel", 100);
    m_itemManager.RegisterItem(StoreItem::ProFlashlight, "ProFlashlight", 200);
    m_itemManager.RegisterItem(StoreItem::Teleporter, "Teleporter", 300);
    m_itemManager.RegisterItem(StoreItem::InverseTeleporter, "InverseTeleporter", 400);
    m_itemManager.RegisterItem(StoreItem::Backpack, "Backpack", 500);
    m_itemManager.RegisterItem(StoreItem::HydraulicsMk2, "HydraulicsMk2", 1000);  
}

void Game::PrintCurrentInfo()
{
    ItemManager item;
    std::cout << DEADLY_CORP_TITLE;
    std::cout << "\nWelcome\nWe trust you will be a great asset to the company!\n";
    std::cout << "\n================ DAY " << m_currentDay << " ================\n";
    std::cout << "Current cargo value : $" << m_total << "\n";
    std::cout << "Current balance: $" << m_balance << "\n"; // Access player balance through item
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
    std::getline(std::cin, x);
    std::vector<std::string> arguments;
    util::lower(x);
    util::splitArguments(x, arguments);

    if (arguments.size() > 0 && x == "buy") {
        auto buy = ConvertStringToStoreItem(arguments[0]);

        if (buy == StoreItem::Invalid) {
            std::cout << "This command is not available at this time.";
        }

        else {
            m_itemManager.BuyItem(buy, m_balance);
        }
        return true;
    }

    auto choice = ConvertStringToChoice(x);

    switch (choice) {
    case Choice::Moons:
        std::cout << "\nWelcome to the exomoons catalogue.\nTo route the autopilot to a moon, use the word ROUTE.\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "\n* Corporation\n* Prototyping\n* Insurance\n* Pledge\n* Defence\n";
        return true;

    case Choice::Store:
        std::cout << "\nWelcome to the Corporation store.\nUse the word BUY on any item.\n";
        std::cout << "---------------------------------------------\n";
        m_itemManager.DisplayStore();
        std::cout << "\nBalance: $" << m_balance << "\n";
        return true;
    case Choice::Inventory:
        std::cout << "\nThe following items are available.\n";
        std::cout << "---------------------------------------------\n";
        m_itemManager.DisplayInventory();
        return true;
    case Choice::Exit:
        std::cout << "\n---------------------------------------------------\n";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<<<<<<<<\n";
        std::cout << "\n---------------------------------------------------\n";
        return false;
    }
}



