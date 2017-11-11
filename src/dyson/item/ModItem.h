#ifndef MODITEM_H
#define MODITEM_H

#include "src/engine/item/Item.h"

class ModItem : public Item {
    private:
       double cVal;

    public: 
        ModItem(std::string name, double CVal);
        double getCVal(){ return cVal;};
};

#endif
