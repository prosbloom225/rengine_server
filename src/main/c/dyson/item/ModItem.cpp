#include "ModItem.h"

ModItem::ModItem(std::string const &modName, std::string const &itemName, double CVal)
    : Item(modName, itemName) {
    cVal = CVal;
    LOG(DEBUG) << this;
}
