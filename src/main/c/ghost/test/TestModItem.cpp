
#include "include/catch.h"
#include "ghost/item/ModItem.h"
#include "ghost/item/ModItemWeapon.h"

TEST_CASE("Test ModItem builder defaults", "[moditem]") {
    LOG(INFO) << "Test ModItem builder defaults";
    ModItem *item = ModItem::Builder()
        .build();
    REQUIRE(strcmp(item->getModName(), "ghost") == 0);
    REQUIRE(strcmp(item->getName(), "null") == 0);
    REQUIRE(item->getCVal() == 0.0);
    REQUIRE(item->getIlvl() == 0);
}

TEST_CASE("Test ModItem builder properties", "[moditem]") {
    LOG(INFO) << "Test ModItem builder properties";
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

TEST_CASE("Test Ghost mod Weapon building", "[moditem]") {
    LOG(INFO) << "Test Ghost mod weapon building";
    ModItemWeapon *item= ModItemWeapon::Builder()
        .setName("testModItem1")
        .setCVal(2.0)
        .setIlvl(2)
        .setAp(5)
        .build();

    REQUIRE(strcmp(item->getModName(), "ghost") == 0);
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getCVal() == 2.0);
    REQUIRE(item->getAp() == 5);
    REQUIRE(item->getIlvl() == 2);
    LOG(DEBUG) << item;
}
