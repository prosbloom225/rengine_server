#include "ItemRegistry.h"

using namespace std;

std::map<int, unique_ptr<Item>> ItemRegistry::items;

int ItemRegistry::addItem(Item *item) {
    // get next available id
    return 0;
}
int ItemRegistry::addItem(int id, Item *item){
    // add item at explicit id
    //
    LOG(DEBUG) << "Adding item: " << id << ": " << item;
    items.insert(std::pair<int, unique_ptr<Item>> (id, unique_ptr<Item>(item)));
    /* LOG(ERROR) << ItemRegistry::getItem(id); */
    return id;
}

Item *ItemRegistry::getItem(int id) {
    // return a deep copy
    Item *ret = ItemRegistry::items.at(id).get();
    LOG(DEBUG) << ret;
    return ItemRegistry::items.at(id).get();
}

void ItemRegistry::clear() {
    LOG(DEBUG) << "Clearing ItemRegistry";
    ItemRegistry::items.clear();
}
void ItemRegistry::dumpRegistry() {
    //TODO - mask this behind debug flag
    LOG(DEBUG) << "dumping ItemRegistry";

    /*
    for (auto x : ItemRegistry::items) {
        LOG(DEBUG) << x.second.getName();
    }
    */
}
