#ifndef MODITEMS_H
#define MODITEMS_H

#include "include/json.h"

#include "ghost/item/ModItem.h"
#include "ghost/lib/LibMisc.h"
#include "engine/registry/ItemRegistry.h"
#include "engine/base/Items.h"

class ModItems : public Items {
    private:
        static int loadItem(int id, ModItem *item);
        static ModItem* ModItemFactory(nlohmann::json json);
    public:
        static void loadItems();
};

#endif
