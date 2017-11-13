#include "include/catch.h"
#include "dyson/item/ModItems.h"

TEST_CASE("Test Dyson mod item loading","[dyson]") {
    LOG(INFO) << "Test Dyson mod item loading";
    ItemRegistry::clear();
    ModItems::loadItems();

    // testModItem0
    ModItem *item = static_cast<ModItem *>(ItemRegistry::getItem(10));

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(item->getCVal() == 7.7);

    // testModItem1
    item = static_cast<ModItem *>(ItemRegistry::getItem(11));

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(item->getCVal() == 33.0);
    /* ItemRegistry::dumpRegistry(); */
}

