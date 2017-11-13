
#include "include/catch.h"
#include "ghost/item/ModItem.h"

TEST_CASE("Test ModItem builder defaults", "[moditem]") {
    ModItem *item = ModItem::Builder()
        .build();
    REQUIRE(strcmp(item->getModName(), "ghost") == 0);
    REQUIRE(strcmp(item->getName(), "null") == 0);
    REQUIRE(item->getCVal() == 0.0);
    REQUIRE(item->getIlvl() == 0);
}

TEST_CASE("Test ModItem builder properties", "[moditem]") {
    ModItem *item = ModItem::Builder()
        .setName("testModItem1")
        .setCVal(2.0)
        .setIlvl(2)
        .build();
    REQUIRE(strcmp(item->getModName(), "ghost") == 0);
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getCVal() == 2.0);
    REQUIRE(item->getIlvl() == 2);
    LOG(DEBUG) << item;
}

