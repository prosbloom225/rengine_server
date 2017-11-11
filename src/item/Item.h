#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "include/easylogging++.h"

class Item {
    private:
        std::string *name;


    public:
        Item(std::string const& itemName);
        const char *toString(){ return name->c_str();};
        friend std::ostream& operator<<(std::ostream& out, const Item *item){
            return out << "name(" << *item->name << ")";
        }

};

#endif
