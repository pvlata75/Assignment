#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::registerItem(Item* item)
{
}

void ItemManager::displayInventory() const
{
}

void ItemManager::displayStore() const
{
}

void ItemManager::buyItem(const std::string& itemName, int& playerBalance)
{
}

Item::Item(const std::string& name, int price)
{
}

std::string Item::getName() const
{
	return std::string();
}

int Item::getPrice() const
{
	return 0;
}
