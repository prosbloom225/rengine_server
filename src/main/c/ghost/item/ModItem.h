#ifndef MODITEM_H
#define MODITEM_H

#include "engine/item/Item.h"

class ModItem : public Item {
    public:
        class Builder;
    protected:
        ModItem(std::string const &modName, std::string const &itemName, int ilvl, double cVal);
       double cVal;
       unsigned int ilvl;

    public: 
        double getCVal(){ return cVal;};
        unsigned int getIlvl(){ return ilvl;};
        friend std::ostream& operator<<(std::ostream& out, const ModItem item){
            return out << "{\"ModItem\" : {"
                << "\"mod\" : \"" << item.modName->c_str() << "\","
                << "\"name\" : \"" << item.name->c_str() << "\","
                << "\"cVal\" : " << item.cVal << ","
                << "\"ilvl\" : " << item.ilvl<< ""
                << "}}";
        }
};


class ModItem::Builder : public Item::Builder {
    protected:
        std::string *name;
        std::string *modName;
        double cVal;
        unsigned int ilvl;

    public:
        static const constexpr char *defaultModName = "ghost";
        static const constexpr double defaultCVal = 0.0;
        static const constexpr int defaultIlvl = 0;

        Builder() : modName(new std::string(defaultModName)), name(new std::string(defaultName)), cVal(defaultCVal), ilvl(defaultIlvl) { }


        // properties need to be overloaded else the builder returns the parent Item::Builder&
        // TODO - could maybe get away with casting as the child Builder???
        // Parent properties
        Builder& setName(std::string *name) { this->name= name; return *this;}
        Builder& setName(const char *name) { this->name= new std::string(name); return *this;}


        // Child properties
        Builder& setCVal(double cVal) { this->cVal = cVal; return *this;}
        Builder& setIlvl(int ilvl) { this->ilvl = ilvl; return *this;}


        ModItem *build() {
            return new ModItem(*this->modName, *this->name, this->ilvl, this->cVal);
        }
};

#endif
