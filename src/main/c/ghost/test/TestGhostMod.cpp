#include "include/catch.h"
#include "ghost/item/ModItems.h"

TEST_CASE("Test Ghost mod item loading","[ghost]") {
    LOG(INFO) << "Test Ghost mod item loading";
    ItemRegistry::clear();
    ModItems::loadItems();

    // testModItem0
    ModItemWeapon *item = static_cast<ModItemWeapon *>(ItemRegistry::getItem(10));

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "ghost") == 0);
    REQUIRE(item->getIlvl() == 1);
    REQUIRE(item->getCVal() == 7.7);
    REQUIRE(item->getAp() == 7);

    // testModItem1
    ModItemArmor *item1 = static_cast<ModItemArmor *>(ItemRegistry::getItem(11));

    // require all properties here
    REQUIRE(strcmp(item1->getName(), "testModItem1") == 0);
    REQUIRE(strcmp(item1->getModName(), "ghost") == 0);
    REQUIRE(item1->getIlvl() == 5);
    REQUIRE(item1->getCVal() == 33.0);
    REQUIRE(item1->getPv() == 2.1);
    REQUIRE(item1->getDv() == 6.6);

    //
    ItemRegistry::dumpRegistry();
}
