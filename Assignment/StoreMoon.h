#ifndef STOREMOON_H
#define STOREMOON_H
#include <string>

enum class StoreMoon
{
	Corporation,
	Prototyping,
	Insurance,
	Pledge,
	Defence,
	Mars,
	Venus,
	Invalid
};

StoreMoon ConvertStringToStoreMoon(std::string input);
#endif // STOREMOON_H
