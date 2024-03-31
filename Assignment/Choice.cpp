#include "Choice.h"
#include <iostream>
#include <cctype>
#include <string>


std::string toLowerAndRemoveSpaces(std::string& str) {
    std::string result;

    for (char c : str) {
        if (!std::isspace(c)) {
            result += std::tolower(c);
        }
    }
    return result;
}

Choice ConvertStringToChoice(std::string input)
{
    std::string lowercase = toLowerAndRemoveSpaces(input);

    if (lowercase == "moons")
        return Choice::Moons;
    else if (lowercase == "store")
        return Choice::Store;
    else if (lowercase == "inventory")
        return Choice::Inventory;
    else if (lowercase == "exit")
        return Choice::Exit;
    else if (lowercase.substr(0, 4) == "buy ") {
        if (lowercase == "buy flashlight" || lowercase == "buy flash")
            return StoreItem::Flashlight;
        else if (lowercase == "buy proflashlight" || lowercase == "buy pro")
            return StoreItem::ProFlashlight;
        else if (lowercase == "buy shovel")
            return StoreItem::Shovel;
        else if (lowercase == "buy teleporter" || lowercase == "buy tele")
            return StoreItem::Teleporter;
        else if (lowercase == "buy inverse teleporter" || lowercase == "buy inverse")
            return StoreItem::InverseTeleporter;
        else if (lowercase == "buy backpack" || lowercase == "buy back")
            return StoreItem::Backpack;
        else if (lowercase == "buy hydraulicsmk2" || lowercase == "buy hyd" || lowercase == "buy hydrau")
            return StoreItem::HydraulicsMk2;
        else {
            std::cout << "Invalid item name";
        }
    else {
        std::cout << "Invalid command";
        return Choice::Unknown;
    }
    }
}
