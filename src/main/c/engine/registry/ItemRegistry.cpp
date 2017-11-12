#include "ItemRegistry.h"

std::map<int, Item> ItemRegistry::items;

int ItemRegistry::addItem(Item *item) {
    // get next available id
    return 0;
}
int ItemRegistry::addItem(int id, Item *item){
    // add item at explicit id
    //
    LOG(DEBUG) << "Adding item: " << item;
    items.insert(std::pair<int, Item>(id, *item));
    return id;
}

Item *ItemRegistry::getItem(int id) {
    // return a deep copy
    Item *ret = ItemRegistry::items.at(id).copy();
    LOG(DEBUG) << ret;
    return ret;
}

void ItemRegistry::dumpRegistry() {
    //TODO - mask this behind debug flag
    LOG(DEBUG) << "dumping ItemRegistry";
    for (auto& x : ItemRegistry::items) {
        LOG(DEBUG) << &x.second;
    }
}
