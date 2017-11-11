#include "Item.h"

Item::Item(std::string const& itemName){
    name = new std::string(itemName);
    LOG(DEBUG) << this << std::endl;
}
