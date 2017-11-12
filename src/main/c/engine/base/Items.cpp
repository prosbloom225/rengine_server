#include "Items.h"

using json = nlohmann::json;

bool Items::loadItem(Item *item){
    ItemRegistry::addItem(item);
    return true;
}

void Items::loadItems(){
    LOG(DEBUG) << "Base itemload called";
    std::ifstream i("./src/main/resources/engine/item/BaseItems.json");
    json j;
    i >> j;
    i.close();
    for(unsigned int i=0;i < j.size();i++){
        LOG(DEBUG) << j[i]["name"] << std::endl;

        Item item = Item::Builder()
            .setName(new std::string("testItem0"))
            .build();
        loadItem(&item);
    }
}
