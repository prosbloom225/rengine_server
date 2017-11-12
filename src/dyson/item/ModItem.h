#ifndef MODITEM_H
#define MODITEM_H

#include "src/engine/item/Item.h"

class ModItem : public Item {
    public:
        class Builder;
    private:
       double cVal;

    public: 
        ModItem(std::string const &modName, std::string const &itemName, double cVal);
        ModItem(std::string const &modName, std::string const &itemName);
        double getCVal(){ return cVal;};
};


class ModItem::Builder : public Item::Builder {
    protected:
        std::string *name;
        std::string *modName;
        double cVal;

    public:
        static const constexpr char *defaultModName = "dyson";
        static const constexpr double defaultCVal = 0.0;

        Builder() : modName(new std::string(defaultModName)), name(new std::string(defaultName)), cVal(defaultCVal) { }


        // properties need to be overloaded else the builder returns the parent Item::Builder&
        // TODO - could maybe get away with casting as the child Builder???
        // Parent properties
        Builder& setModName(std::string *modName) { this->modName = modName; return *this;}
        Builder& setName(std::string *name) { this->name= name; return *this;}
        Builder& setModName(const char *modName) { this->modName = new std::string(modName); return *this;}
        Builder& setName(const char *name) { this->name= new std::string(name); return *this;}


        // Child properties
        Builder& setCVal(double cVal) { this->cVal = cVal; return *this;}

        ModItem build() {
            return ModItem(*this->modName, *this->name, this->cVal);
        }
};

#endif
