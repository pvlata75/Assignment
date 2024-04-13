#include "MoonManager.h"
#include <iostream>
#include "Util.h"
#include "Game.h"
#include "StoreMoon.h"

void MoonManager::RegisterMoon(StoreMoon moonId, std::string name, int cost, int minScrap, int maxScrap, double explorerBaseSurvival) {
    std::unique_ptr<Moon> newMoon = std::make_unique<Moon>(name, cost, minScrap, maxScrap, explorerBaseSurvival);

    m_moons[moonId] = std::move(newMoon);
}

void MoonManager::PrintMoons() {
    std::cout << "\nWelcome to the exomoons catalogue.\nTo route the autopilot to a moon, use the word ROUTE.\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "\n";
    for (auto& [id, moon] : m_moons) {
        std::cout << moon->GetName() << "\n";
    }
}

AbstractMoon* MoonManager::GetMoon(const std::string moonName)
{
    for (auto& [id, moon] : m_moons) {
        if (moon->GetName() == moonName) {
            return moon.get();
        }
    }
}

void MoonManager::RouteToMoon(Game g, const std::string moonName) {
    if (moonName.empty()) {
        std::cout << "Invalid moon name" << std::endl;
        return;
    }
    if (moonName == g.GetCurrentMoon()) {
        std::cout << "Already orbiting " << moonName << std::endl;
        return;
    }

    AbstractMoon* destinationMoon = nullptr;
    for (auto& [id, moon] : m_moons) {
        if (moon->GetName() == moonName) {
            destinationMoon = moon.get();
            break;
        }
    }

    if (destinationMoon == nullptr) {
        std::cout << "Moon not found" << std::endl;
        return;
    }

    // Check if enough funds
    if (destinationMoon->GetCost() > 0) {

        if (g.GetBalance() < destinationMoon->GetCost()) {
            std::cout << "Insufficient funds to travel to " << moonName << std::endl;
            return;
        }

        std::cout << "Confirm travel to " << moonName << " for $"
            << destinationMoon->GetCost() << "? (y/n)" << std::endl;

        std::string confirm;
        std::cin >> confirm;

        if (confirm != "y") {
            std::cout << "Trip canceled" << std::endl;
            return;
        }

        // Charge travel cost
        g.UpdateBalance(-destinationMoon->GetCost());

    }

    // Update current moon
    g.SetCurrentMoon(moonName);

    std::cout << "Now orbiting " << moonName << std::endl;
}
