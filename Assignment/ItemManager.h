#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <vector>
#include <string>
#include "Choice.h"

class Item;

class ItemManager {
private:
    std::vector<Item*> items; 
    int m_playerBalance;

public:
    ItemManager();

    ~ItemManager();

    void registerItem(Item* item);

    void displayInventory();

    void displayStore();

    std::string getItemName(StoreItem item);
    
    int getPlayerBalance();

    int getItemPrice(StoreItem item);

    void buyItem(StoreItem item, int& m_playerBalance);
};

class Item {
private:
    std::string name;
    int price;

public:
    Item(std::string& name, int price);

    std::string getName();

    int getPrice();
};

#endif // ITEM_MANAGER_H
