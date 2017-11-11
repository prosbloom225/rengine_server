#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "include/easylogging++.h"
#include "Recipe.h"

class Item {
    // TODO - builder pattern
    private:
        std::string *name;
        std::string *modName = new std::string("base");
        Recipe recipe;


    public:
        Item(std::string const &modName, std::string const &itemName);
        Item(std::string const &itemName);
        const char *getName(){ return name->c_str();};
        const char *getModName(){ return modName->c_str();};
        Item *copy();
        friend std::ostream& operator<<(std::ostream& out, const Item *item){
            return out << "name(" 
                << item->modName->c_str() 
                << ":" 
                << item->name->c_str()
                << ")";
        }

};

#endif
