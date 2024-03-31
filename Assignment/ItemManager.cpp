#include "ItemManager.h"
#include <iostream>
#include "Choice.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
	for (Item* item : items) {
		delete item;
	}
}

void ItemManager::registerItem(Item* item)
{
	items.push_back(item);
}

void ItemManager::displayInventory()
{
	std::cout << "\n";
	for (Item* item : items) {
		std::cout << "* " << item->getName() << "\n";
	}
}

void ItemManager::displayStore()
{
	std::cout << "\nWelcome to the Corporation store.\nUse the word BUY on any item.\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "\n* Flashlight // Price : $60";
	std::cout << "\n* Shovel // Price : $100";
	std::cout << "\n* Pro-flashlight // Price : $200";
	std::cout << "\n* Teleporter // Price : $300";
	std::cout << "\n* Inverse-teleporter // Price : $400";
	std::cout << "\n* Backpack // Price : $500";
	std::cout << "\n* Hydaulics-Mk2 // Price : $1000\n";
}

void ItemManager::buyItem(StoreItem item, int& m_playerBalance)
{
	int price = getItemPrice(item);
	if (price == -1) {
		std::cout << "\nInvalid item selected.\n";
		return;
	}

	if (m_playerBalance >= price) {
		std::cout << "\nSuccessfully bought " << getItemName(item) << "\n";
		m_playerBalance -= price;
		std::cout << "Your balance is now: $" << m_playerBalance << "\n";
	}
	else {
		std::cout << "\nYou don't have enough money to buy this\n";
	}
}

Item::Item(std::string& name, int price) : name(name), price(price)
{
}

std::string Item::getName()
{
	return name;
}

int Item::getPrice()
{
	return price;
}

std::string ItemManager::getItemName(StoreItem item) {
	switch (item) {
	case StoreItem::Flashlight:
		return "Flashlight";
	case StoreItem::Shovel:
		return "Shovel";
	case StoreItem::ProFlashlight:
		return "ProFlashlight";
	case StoreItem::Teleporter:
		return "Teleporter";
	case StoreItem::InverseTeleporter:
		return "InverseTeleporter";
	case StoreItem::Backpack:
		return "Backpack";
	case StoreItem::HydraulicsMk2:
		return "HydraulicsMk2";
	default:
		return "Unknown Item";
	}
}

int ItemManager::getPlayerBalance()
{
	// Initialize or retrieve player balance
	return m_playerBalance = 5000;
}

int ItemManager::getItemPrice(StoreItem item) {
	switch (item) {
	case StoreItem::Flashlight:
		return 60;
	case StoreItem::Shovel:
		return 100;
	case StoreItem::ProFlashlight:
		return 200;
	case StoreItem::Teleporter:
		return 300;
	case StoreItem::InverseTeleporter:
		return 400;
	case StoreItem::Backpack:
		return 500;
	case StoreItem::HydraulicsMk2:
		return 1000;
	default:
		return -1; // Invalid item, return -1
	}
}
