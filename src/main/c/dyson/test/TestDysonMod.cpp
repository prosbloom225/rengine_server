#include "include/catch.h"
#include "dyson/item/ModItems.h"

TEST_CASE("Test Dyson mod item loading","[dyson]") {
    LOG(INFO) << "Test Dyson mod item loading";
    ItemRegistry::clear();
    ModItems::loadItems();
    /* ItemRegistry::dumpRegistry(); */
    Item *item = ItemRegistry::getItem(10);
    ModItem *modItem = static_cast<ModItem *>(item);
    std::cout << std::endl << item->getName() << std::endl;

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
};
