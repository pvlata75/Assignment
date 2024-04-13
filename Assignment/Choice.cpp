#include "Choice.h"
#include <iostream>
#include <cctype>
#include <string>
#include "Util.h"

Choice ConvertStringToChoice(std::string input)
{
    Util::lower(input);

    if (input == "moons")
        return Choice::Moons;
    else if (input == "store")
        return Choice::Store;
    else if (input == "inventory")
        return Choice::Inventory;
    else if (input == "exit")
        return Choice::Exit;
    else
        return Choice::Unknown;
}


