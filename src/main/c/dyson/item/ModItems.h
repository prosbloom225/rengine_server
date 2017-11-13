#ifndef MODITEMS_H
#define MODITEMS_H

#include "include/json.h"

#include "dyson/item/ModItem.h"
#include "engine/registry/ItemRegistry.h"
#include "engine/base/Items.h"

class ModItems : public Items {
    private:
        static int loadItem(int id, ModItem *item);
    public:
        static void loadItems();
};

#endif
