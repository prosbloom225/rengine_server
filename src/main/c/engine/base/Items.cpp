#include "Items.h"

bool Items::loadItem(Item *item){
    ItemRegistry::addItem(item);
    return true;
}
void Items::loadItems(){
    LOG(INFO) << "Base itemload called";
}
