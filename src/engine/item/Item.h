#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "include/easylogging++.h"
#include "Recipe.h"

class Item {

    public:
        class Builder;
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

class Item::Builder {
    private:
        std::string *name;
        std::string *modName;
        /* Recipe recipe; */
    public:
        static const constexpr char *defaultModName = "base";
        static const constexpr char *defaultName = "null";
        /* static const constexpr Recipe defaultRecipe = NULL;//uncraftable */

        Builder() : modName(new std::string(defaultModName)), name(new std::string(defaultName)) { }

        Builder& setModName(std::string *modName) { this->modName = modName; return *this;}
        Builder& setName(std::string *name) { this->name= name; return *this;}
        /* Builder& setRecipe(Recipe recipe) { this->recipe= recipe; return this;} */

        // overloads for cstr
        Builder& setModName(const char *modName) { this->modName = new std::string(modName); return *this;}
        Builder& setName(const char *name) { this->name= new std::string(name); return *this;}

        Item build() {
            return Item(*this->modName, *this->name);
        }
};

#endif
