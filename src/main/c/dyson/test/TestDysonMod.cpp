#include "include/catch.h"
#include "dyson/item/ModItems.h"

TEST_CASE("Test Dyson mod item loading","[dyson]") {
    /* ItemRegistry::clear(); */
    ModItems::loadItems();
    /* ItemRegistry::dumpRegistry(); */
    Item *item = (ModItem*)ItemRegistry::getItem(0);
    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "test") == 0);
};
