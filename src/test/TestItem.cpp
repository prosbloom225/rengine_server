#include "include/catch.h"
#include "../item/Item.h"


TEST_CASE("Test basic item", "[item]") {
    Item *item = new Item("testItem1");

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem1") == 0);
}
