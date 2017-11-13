#include "ModItems.h"

using json = nlohmann::json;

int ModItems::loadItem(int id, ModItem *item){
    int ret = ItemRegistry::addItem(id, item);
    return id;
}
void ModItems::loadItems(){
    LOG(DEBUG) << "Base itemload called";
    std::ifstream i("./src/main/resources/dyson/item/ModItems.json");
    json j;
    i >> j;
    i.close();
    for(unsigned int i=0;i < j.size();i++){
        std::string name = j[i]["name"].get<std::string>();
        double cVal = j[i]["cVal"];
        int id = j[i]["id"];
        ModItem item = ModItem::Builder()
            .setName(&name)
            .setCVal(cVal)
            .build();
        LOG(DEBUG) << item;
        loadItem(id, &item);
    }
}
