#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <vector>
#include <string>

class Item;

class ItemManager {
private:
    std::vector<Item*> items; 

public:
    ItemManager();

    ~ItemManager();

    void registerItem(Item* item);

    void displayInventory() const;

    void displayStore() const;

    void buyItem(const std::string& itemName, int& playerBalance);
};

class Item {
private:
    std::string name;
    int price;

public:

    Item(const std::string& name, int price);

    std::string getName() const;

    int getPrice() const;
};

#endif // ITEM_MANAGER_H
