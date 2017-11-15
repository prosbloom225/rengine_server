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
        ModItem *item = ModItemFactory(j[i]);
        loadItem(j[i]["id"], item);
    }
}

ModItem* ModItems::ModItemFactory(json json) {
    // base props
    std::string type = json["type"].get<std::string>();
    std::string name = json["name"].get<std::string>();
    double cVal = json["cVal"];
    int id = json["id"];
    int ilvl = json["ilvl"];

    //
    ModItem *item;

    if (type.compare("WEAPON") == 0) {
        LOG(DEBUG) << "Building Weapon item...";
        item = ModItem::Builder()
            .setName(&name)
            .setCVal(cVal)
            .setIlvl(ilvl)
            .build();
    } else if (type.compare("ARMOR") == 0) {
        LOG(DEBUG) << "Building Armor item...";
        item = ModItem::Builder()
            .setName(&name)
            .setCVal(cVal)
            .setIlvl(ilvl)
            .build();
    } else {
        std::cout << "Default";
        item = ModItem::Builder()
            .setName(&name)
            .setCVal(cVal)
            .setIlvl(ilvl)
            .build();
    }
    LOG(DEBUG) << "Loaded from json: " << id << " - " << item;
    return item;
}

