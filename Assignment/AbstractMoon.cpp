#include "AbstractMoon.h"
#include "Game.h"
#include <iostream>

const std::string AbstractMoon::name()
{
	return moonName;
}

void AbstractMoon::onDayBegin(Game g)
{
	std::cout << "Proceed with caution as the moon is currently ";

	switch (weather) {
	case MoonWeather::Clear:
		break;
	case MoonWeather::Flooded:
		std::cout << "Flooded\n";
		break;
	case MoonWeather::Eclisped:
		std::cout << "Eclisped\n";
		break;
	case MoonWeather::Stormy:
		std::cout << "Stormy\n";
		break;
	}
}

void AbstractMoon::sellCargo(Game g, int amount)
{
}

void AbstractMoon::sendEmployees(Game g, int count)
{
}

void AbstractMoon::printWelcomeMessage()
{
	std::cout << "Welcome to " << moonName << "!\n";
	std::cout << "\nCurrent cargo value: $";
}
