#include "ModItemArmor.h"

ModItemArmor::ModItemArmor(std::string const &modName, std::string const &itemName, int ilvl, double cVal, double pv, double dv)
    : ModItem(modName, itemName, ilvl, cVal) {
    this->pv = pv;
    this->dv = dv;
    LOG(DEBUG) << this;
}
