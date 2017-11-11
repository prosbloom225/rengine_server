#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    protected:
        std::string *name;

    public:
        Item(std::string const& itemName);
};

#endif
