#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H
#include <map>
#include "../item/Item.h"

class ItemRegistry {
    private:
        static std::map<int, Item> items;
    public:
        ItemRegistry();
        int addItem(Item *item);
        int addItem(int id, Item *item);
};

#endif
