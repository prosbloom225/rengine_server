#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include <map>
#include "../item/Item.h"

class ItemRegistry {
    private:
        static std::map<int, Item> items;
    public:
        static int addItem(Item *item);
        static int addItem(int id, Item *item);
        static Item *getItem(int id);
        static void dumpRegistry();
};

#endif
