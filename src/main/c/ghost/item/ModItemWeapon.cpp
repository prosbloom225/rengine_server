#include "ModItemWeapon.h"

ModItemWeapon::ModItemWeapon(std::string const &modName, std::string const &itemName, int ilvl, double cVal)
    : ModItem(modName, itemName, ilvl, cVal) {
    this->cVal = cVal;
    this->ilvl = ilvl;
    LOG(DEBUG) << this;
}
