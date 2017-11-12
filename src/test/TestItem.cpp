#include "include/catch.h"
#include "../engine/item/Item.h"


TEST_CASE("Test basic item", "[item]") {
    Item item = Item::Builder()
        .setModName(new std::string("test"))
        .setName(new std::string("testItem1"))
        .build();

    // require all properties here
    REQUIRE(strcmp(item.getName(), "testItem0") == 0);
    REQUIRE(strcmp(item.getModName(), "test") == 0);
}

