#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <vector>
#include <string>
#include "StoreItem.h"
#include <map>


class ItemManager {
private:
    std::map<StoreItem, std::pair<std::string, int>> m_items = {};
    
public:

    void RegisterItem(StoreItem item, std::string GetName, int price);

    void DisplayInventory();

    void DisplayStore();
    
    void BuyItem(StoreItem item, int m_playerBalance);
};

#endif // ITEM_MANAGER_H
