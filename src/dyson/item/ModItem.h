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
        double cVal;
    public:
        /* static const constexpr double defaultCval = 0; */

        Builder& setCval(double cVal) { this->cVal=cVal; return *this;}

        using Item::Builder::build;
        ModItem build() {
            return ModItem(*this->modName, *this->name, this->cVal);
        }
};

#endif
