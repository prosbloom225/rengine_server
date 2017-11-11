#include "Item.h"

Item::Item(std::string const& itemName){
    name = *new std::string(itemName);
    LOG(DEBUG) << this << std::endl;
}

Item *Item::copy() {
    Item *ret = this;
    // copy constructor does a deep copy?
    /* Item *ret; */
    /* memcpy(&ret, this, sizeof(this)); */
    void *a = this;
    LOG(DEBUG) << "address of original: " << a;
    LOG(DEBUG) << "address of new:      " << &ret;
    return ret;
}
