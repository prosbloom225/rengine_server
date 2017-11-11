#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include <map>
#include "../item/Item.h"

class ItemRegistry {
    private:
        std::map<int, Item> items;
    public:
        ItemRegistry();
        int addItem(Item *item);
        int addItem(int id, Item *item);
        Item *getItem(int id);
        void dumpRegistry();
};

#endif
