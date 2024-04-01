#include "StoreItem.h"
#include "Util.h"

StoreItem ConvertStringToStoreItem(std::string input)
{
    util::lower(input);
    if (input == "flashlight" || input == "flash")
        return StoreItem::Flashlight;
    else if (input == "proflashlight" || input == "pro")
        return StoreItem::ProFlashlight;
    else if (input == "shovel")
        return StoreItem::Shovel;
    else if (input == "teleporter" || input == "tele")
        return StoreItem::Teleporter;
    else if (input == "inverse teleporter" || input == "inverse")
        return StoreItem::InverseTeleporter;
    else if (input == "backpack" || input == "back")
        return StoreItem::Backpack;
    else if (input == "hydraulicsmk2" || input == "hyd" || input == "hydrau")
        return StoreItem::HydraulicsMk2;
    else {
        return StoreItem::Invalid;
    }
}
