#include "Moon.h"
#include "Game.h" 
#include "AbstractMoon.h"
#include <iostream>
#include <random>
#include <string>

class Moon : public AbstractMoon {
public:
    Moon::Moon(const std::string name, int cost, int MinScrap, int MaxScrap, double explorerBaseSurvival)
    : AbstractMoon(name, cost, MinScrap, MaxScrap, explorerBaseSurvival) {
        
        std::mt19937 gen(std::time(nullptr));

        std::uniform_int_distribution<int> dist(0, static_cast<int>(MoonWeather::Count) - 1);

        int random = dist(gen);

        weather = static_cast<MoonWeather>(random);
    }

    void Moon::OnDayBegin(Game g)
    {
        std::cout << "Proceed with caution as the moon is currently ";
        switch (weather) {
        case MoonWeather::Clear:
            std::cout << "Clear\n";
            break;
        case MoonWeather::Flooded:
            std::cout << "Flooded\n";
            break;
        case MoonWeather::Eclipsed:
            std::cout << "Eclipsed\n";
            break;
        case MoonWeather::Stormy:
            std::cout << "Stormy\n";
            break;
        }
    }

    int Moon::GetCost() const
    {
        return cost;
    }

    void Moon::SellCargo(Game g, int amount)
    {
        if (amount <= 0) {
            std::cout << "Invalid amount of cargo to sell\n";
            return;
        }

        int cargoValue = amount * cargoPrice;
        int balance = g.GetBalance(); 
        balance += cargoValue; 
        g.GetBalance += balance; 
        std::cout << "Sold " << amount << " units of cargo for $" << cargoValue << "\n";
    }

    void Moon::SendEmployee(Game g, int numExplorers)
    {
        if (numExplorers > g.GetNumEmployees()) {
            std::cout << "Not enough employees to send " << numExplorers << std::endl;
            return;
        }

        if (numExplorers <= 0) {
            std::cout << "Invalid number of explorers: " << numExplorers << std::endl;
            return;
        }

        double explorerSurvivalChance = explorerBaseSurvival;
        double scrapAmountMultiplier = 1.0;

        MoonWeather currentWeather = weather;
        switch (currentWeather) {
        case MoonWeather::Clear:
            explorerSurvivalChance *= 0.7;
            break;
        case MoonWeather::Flooded:
            scrapAmountMultiplier *= 0.75;
            break;
        case MoonWeather::Stormy:
            explorerSurvivalChance *= 0.8;
            break;
        case MoonWeather::Eclipsed:
            explorerSurvivalChance *= 0.9;
        default:
            break;
        }

        int totalRevenue = 0;
        int deadExplorers = 0;

        for (int i = 0; i < numExplorers; i++) {
            if (GetRandomChance() < explorerSurvivalChance) {
                totalRevenue += GetRandomScrap(minScrap, maxScrap) * scrapAmountMultiplier;
            }
            else {
                deadExplorers++;
            }
        }

        std::cout << numExplorers - deadExplorers << " explorers returned with $"
            << totalRevenue << " scrap. " << deadExplorers << " died." << std::endl;

        g.updateCargo(totalRevenue);
        g.setAliveEmployee(g.GetNumEmployees() - deadExplorers);
    }

};