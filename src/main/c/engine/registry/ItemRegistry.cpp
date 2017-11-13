#include "ItemRegistry.h"

using namespace std;

std::map<int, Item*> ItemRegistry::items;

int ItemRegistry::addItem(Item *item) {
    // get next available id
    return 0;
}
int ItemRegistry::addItem(int id, Item *item){
    // add item at explicit id
    //
    LOG(DEBUG) << "Adding item: " << id << ": " << item;
    /* items.insert(std::pair<int, Item*> (id, item)); */
    items[id] = item;
    /* LOG(ERROR) << ItemRegistry::getItem(id); */
    return id;
}

Item *ItemRegistry::getItem(int id) {
    // return a deep copy
    /* LOG(DEBUG) << "Getting item: " << id; */
    return ItemRegistry::items.at(id)->copy();
}

void ItemRegistry::clear() {
    LOG(DEBUG) << "Clearing ItemRegistry";
    ItemRegistry::items.clear();
}
void ItemRegistry::dumpRegistry() {
    //TODO - mask this behind debug flag
    LOG(DEBUG) << "dumping ItemRegistry";

    for (auto x : ItemRegistry::items) {
        LOG(DEBUG) << x.second;
    }
}
