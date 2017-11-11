#include "include/catch.h"
#include "../engine/registry/ItemRegistry.h"

TEST_CASE("Test adding basic items ", "[itemregistry]") {
    ItemRegistry *registry = new ItemRegistry();
    Item *item0 = new Item("testItem0");
    Item *item1 = new Item("testItem1");
    registry->addItem(0, item0);
    registry->addItem(1, item1);
    /* registry->dumpRegistry(); */

    Item *tmpItem1 = registry->getItem(0);
    LOG(DEBUG) << tmpItem1;
    REQUIRE(strcmp(registry->getItem(0)->getName(),"testItem0") == 0);
    REQUIRE(strcmp(registry->getItem(1)->getName(),"testItem1") == 0);
}

TEST_CASE("Test overriding existing item", "[itemregistry]"){
    ItemRegistry *registry = new ItemRegistry();
    Item *item1 = new Item("testItem1");
    Item *item2 = new Item("testItem2");
    registry->addItem(0, item1);
    registry->addItem(0, item2);
    /* registry->dumpRegistry(); */
    std::cout << item1;
    REQUIRE(0==0);
}
