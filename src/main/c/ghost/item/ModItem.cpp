#include "ModItem.h"

ModItem::ModItem(std::string const &modName, std::string const &itemName, int ilvl, double cVal)
    : Item(modName, itemName) {
    this->cVal = cVal;
    this->ilvl = ilvl;
    LOG(DEBUG) << this;
}
