#ifndef MODITEMARMOR_H
#define MODITEMARMOR_H

#include "ghost/item/ModItem.h"

class ModItemArmor : public ModItem {
    public:
        class Builder;
    protected:
        ModItemArmor(std::string const &modName, std::string const &itemName, int ilvl, double cVal, double pv, double dv);
        double pv;
        double dv;

    public: 
        double getPv(){ return pv;};
        double getDv(){ return dv;};
        friend std::ostream& operator<<(std::ostream& out, const ModItemArmor item){
            return out << "{\"ModItem\" : {"
                << "\"mod\" : \"" << item.modName->c_str() << "\","
                << "\"name\" : \"" << item.name->c_str() << "\","
                << "\"cVal\" : " << item.cVal << ","
                << "\"ilvl\" : " << item.ilvl<< ""
                << "}}";
        }
};


class ModItemArmor::Builder : public ModItem::Builder {
    protected:
        double pv;
        double dv;

    public:
        static const constexpr double defaultDv = 0;
        static const constexpr double defaultPv = 0;

        Builder() : pv(defaultPv), dv(defaultDv){ }

        // properties need to be overloaded else the builder returns the parent Item::Builder&
        // TODO - could maybe get away with casting as the child Builder???
        // Parent properties
        Builder& setName(std::string *name) { this->name= name; return *this;}
        Builder& setName(const char *name) { this->name= new std::string(name); return *this;}
        Builder& setCVal(double cVal) { this->cVal = cVal; return *this;}
        Builder& setIlvl(int ilvl) { this->ilvl = ilvl; return *this;}


        // Child properties
        Builder& setPv(double pv) { this->pv= pv; return *this;}
        Builder& setDv(double dv) { this->dv= dv; return *this;}
        


        ModItemArmor *build() {
            return new ModItemArmor(*this->modName, *this->name, this->ilvl, this->cVal, this->pv, this->dv);
        }
};

#endif
