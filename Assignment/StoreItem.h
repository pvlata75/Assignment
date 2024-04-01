#ifndef STORE_ITEM
#define STORE_ITEM

#include <string>

enum class StoreItem {
    Flashlight,
    Shovel,
    ProFlashlight,
    Teleporter,
    InverseTeleporter,
    Backpack,
    HydraulicsMk2,
    Invalid
};

StoreItem ConvertStringToStoreItem(std::string input);

#endif