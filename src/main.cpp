#include "item/Item.h"
#include "registry/ItemRegistry.h"
#include "include/easylogging++.h"

INITIALIZE_EASYLOGGINGPP


int main() {
    LOG(INFO) << "Begin!";
    Item *item = new Item("testItem");
    LOG(INFO) << item << std::endl;
    ItemRegistry *registry = new ItemRegistry();

    return 0;
}
