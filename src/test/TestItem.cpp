#include "include/catch.h"
#include "../engine/item/Item.h"


TEST_CASE("Test basic item", "[item]") {
    Item *item = new Item("test", "testItem1");

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem1") == 0);
    REQUIRE(strcmp(item->getModName(), "test") == 0);
}
