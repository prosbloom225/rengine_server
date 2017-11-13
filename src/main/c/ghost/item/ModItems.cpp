#include "ModItems.h"

using json = nlohmann::json;

int ModItems::loadItem(int id, ModItem *item){
    int ret = ItemRegistry::addItem(id, item);
    return id;
}
void ModItems::loadItems(){
    LOG(DEBUG) << "Mod itemload called";
    /* std::ifstream i("./src/main/resources/ghost/item/ModItems.json"); */
    std::ifstream i(LibMisc::MODITEMS_JSON);
    json j;
    i >> j;
    i.close();
    for(unsigned int i=0;i < j.size();i++){
        std::string name = j[i]["name"].get<std::string>();
        double cVal = j[i]["cVal"];
        int id = j[i]["id"];
        int ilvl = j[i]["ilvl"];
        ModItem *item = ModItem::Builder()
            .setName(&name)
            .setCVal(cVal)
            .setIlvl(ilvl)
            .build();
        LOG(DEBUG) << "Loaded from json: " << id << " - " << item;
        loadItem(id, item);
    }
}
