#ifndef CHOICE_H
#define CHOICE_H


#include <string>
#include <cctype>

enum class Choice {
	Moons,
	Store,
	Inventory,
	Exit,
	Unknown
};

enum class Planet {
	Corporation,
	Prototyping,
	Insurance,
	Pledge,
	Defence
};

enum class StoreItem {
	Flashlight,
	Shovel,
	ProFlashlight,
	Teleporter,
	InverseTeleporter,
	Backpack,
	HydraulicsMk2
};

enum class MoonWeather {
	Clear = 0,
	Flooded,
	Eclipsed,
	Stormy
};

Choice ConvertStringToChoice(std::string input);

#endif // CHOICE_H