#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "include/easylogging++.h"

class Item {
    private:
        std::string name;


    public:
        Item(std::string const& itemName);
        const char *getName(){ return name.c_str();};
        Item *copy();
        friend std::ostream& operator<<(std::ostream& out, const Item *item){
            return out << "name(" << item->name << ")";
        }

};

#endif
