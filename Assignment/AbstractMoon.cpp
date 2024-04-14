#include "AbstractMoon.h" 
#include "Game.h"
#include <iostream>
#include "Util.h"
#include <random>


AbstractMoon::AbstractMoon(const std::string name, int cost, int minScrap, int maxScrap, double explorerBaseSurvival) : 
    moonName(name), cost(cost), minScrap(minScrap), maxScrap(maxScrap), explorerBaseSurvival(explorerBaseSurvival)
{
    std::mt19937 gen(std::random_device{}());

    std::uniform_int_distribution dist(0, static_cast<int>(MoonWeather::Count) - 1);

    weather = static_cast<MoonWeather>(dist(gen));
}

std::string AbstractMoon::GetName() const
{
	return moonName;
}

int AbstractMoon::GetRandomScrap(int min, int max)
{
    static std::mt19937 generator;
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

double AbstractMoon::GetRandomChance()
{
    static std::mt19937 generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

void AbstractMoon::OnDayBegin(Game g)
{
	std::cout << "Proceed with caution as the moon is currently " << static_cast<int>(weather) << "\n";

	switch (weather) {
	case MoonWeather::Clear:
		break;
	case MoonWeather::Flooded:
		std::cout << "Flooded\n";
		break;
	case MoonWeather::Eclipsed:
		std::cout << "Eclisped\n";
		break;
	case MoonWeather::Stormy:
		std::cout << "Stormy\n";
		break;
	}
}

void AbstractMoon::SellCargo(Game g, int amount)
{
	if (amount <= 0)
	{
		std::cout << "Invalid amount of cargo to sell\n";
		return;
	}

	int CargoValue = amount * 5;
	int balance = g.GetBalance();
	balance += CargoValue;

	std::cout << CargoValue << "\n";

	std::cout << "You sold " << amount << " cargo for $" << CargoValue << "\n";
}

void AbstractMoon::SendEmployee(Game g, int numExplorers)
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

    g.UpdateValue(totalRevenue);
    g.SetEmployees(g.GetNumEmployees() - deadExplorers);
}

std::string AbstractMoon::GetWeather()
{
    switch (weather) {
    case MoonWeather::Clear:
        return "Clear";
    case MoonWeather::Flooded:
        return "Flooded";
    case MoonWeather::Eclipsed:
        return "Eclipsed";
    case MoonWeather::Stormy:
        return "Stormy";
    }
    return "Unknown";
}

int AbstractMoon::GetCost() const
{
    return cost;
}


