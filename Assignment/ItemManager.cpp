#include "ItemManager.h"
#include <iostream>
#include "Choice.h"

void ItemManager::RegisterItem(StoreItem item, std::string name, int price)
{
	m_items[item] = std::make_pair(name, price);
}

void ItemManager::DisplayInventory()
{
	std::cout << "\n";
	for (auto [item, data] : m_items) {
		std::cout << "* " << data.first << "\n";
	}
}

void ItemManager::DisplayStore()
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

void ItemManager::BuyItem(StoreItem item, int& m_playerBalance)
{
	int price = m_items[item].second;

	if (price != -1) {
		if (m_playerBalance >= price) {
			std::cout << "\nSuccessfully bought " << m_items[item].first << "\n";
			m_playerBalance -= price;
			m_items[item].second = -1;
			std::cout << "Your balance is now: $" << m_playerBalance << "\n";
		}
		else {
			std::cout << "\nYou don't have enough money to buy this\n";
		}
	}
	else {
		std::cout << "You already own a " << m_items[item].first << ".\n";
	}

}
