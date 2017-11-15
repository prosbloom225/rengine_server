#ifndef MODITEMWEAPON_H
#define MODITEMWEAPON_H

#include "ghost/item/ModItem.h"

class ModItemWeapon : public ModItem {
    public:
        class Builder;
    protected:
        ModItemWeapon(std::string const &modName, std::string const &itemName, int ilvl, double cVal, int ap);
        unsigned int ap;

    public: 
        unsigned int getAp(){ return ap;};
        friend std::ostream& operator<<(std::ostream& out, const ModItemWeapon item){
            return out << "{\"ModItem\" : {"
                << "\"mod\" : \"" << item.modName->c_str() << "\","
                << "\"name\" : \"" << item.name->c_str() << "\","
                << "\"cVal\" : " << item.cVal << ","
                << "\"ilvl\" : " << item.ilvl<< ""
                << "}}";
        }
};


class ModItemWeapon::Builder : public ModItem::Builder {
    protected:
        int ap;

    public:
        static const constexpr int defaultAp= 0;

        Builder() : ap(defaultAp) { }

        // properties need to be overloaded else the builder returns the parent Item::Builder&
        // TODO - could maybe get away with casting as the child Builder???
        // Parent properties
        Builder& setName(std::string *name) { this->name= name; return *this;}
        Builder& setName(const char *name) { this->name= new std::string(name); return *this;}
        Builder& setCVal(double cVal) { this->cVal = cVal; return *this;}
        Builder& setIlvl(int ilvl) { this->ilvl = ilvl; return *this;}


        // Child properties
        Builder& setAp(int ap) { this->ap= ap; return *this;}
        


        ModItemWeapon *build() {
            return new ModItemWeapon(*this->modName, *this->name, this->ilvl, this->cVal, this->ap);
        }
};

#endif
