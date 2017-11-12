#ifndef ITEMS_H
#define ITEMS_H

#include "src/engine/item/Item.h"

class Items {
    private:
        static bool loadItem(Item *item);
    public:
        static void loadItems();
};

#endif
