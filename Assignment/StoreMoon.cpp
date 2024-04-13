#include "StoreMoon.h"
#include "Util.h"

StoreMoon ConvertStringToStoreMoon(std::string input)
{
	Util::lower(input);
	if (input == "corporation" || input == "corpo" || input == "corp")
		return StoreMoon::Corporation;
	else if (input == "prototyping" || input == "proto" || input == "prot")
		return StoreMoon::Prototyping;
	else if (input == "insurance" || input == "insur" || input == "ins")
		return StoreMoon::Insurance;
	else if (input == "pledge" || input == "pled")
		return StoreMoon::Pledge;
	else if (input == "defence" || input == "def")
		return StoreMoon::Defence;
	else if (input == "mars")
		return StoreMoon::Mars;
	else if (input == "venus" || input == "ven")
		return StoreMoon::Venus;
	else {
		return StoreMoon::Invalid;
	}
}
