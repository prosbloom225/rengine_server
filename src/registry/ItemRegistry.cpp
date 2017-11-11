#include "ItemRegistry.h"

ItemRegistry::ItemRegistry() {
}

int ItemRegistry::addItem(Item *item) {
    // get next available id
    return 0;
}
int ItemRegistry::addItem(int id, Item *item){
    // add item at explicit id
    //
    /* log_info("Adding item: %s", item->toString()); */
    /* items[id] = &item; */
    return id;
}
