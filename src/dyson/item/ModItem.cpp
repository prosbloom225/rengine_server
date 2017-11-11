#include "ModItem.h"

ModItem::ModItem(std::string name, double CVal) 
    : Item(name) {
    cVal = CVal;
    LOG(DEBUG) << this;
}
