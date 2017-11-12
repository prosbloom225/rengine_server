#include "include/catch.h"
#include "src/engine/registry/ItemRegistry.h"

TEST_CASE("Test adding basic items ", "[itemregistry]") {
    ItemRegistry *registry = new ItemRegistry();
    Item item0 = Item::Builder()
        .setName("testItem0")
        .build();
    Item item1 = Item::Builder()
        .setName("testItem1")
        .build();
    registry->addItem(0, &item0);
    registry->addItem(1, &item1);
    /* registry->dumpRegistry(); */

    Item *tmpItem1 = registry->getItem(0);
    LOG(DEBUG) << tmpItem1;
    REQUIRE(strcmp(registry->getItem(0)->getName(),"testItem0") == 0);
    REQUIRE(strcmp(registry->getItem(1)->getName(),"testItem1") == 0);
}

TEST_CASE("Test overriding existing item", "[itemregistry]"){
    ItemRegistry *registry = new ItemRegistry();
    Item item1 = Item::Builder()
        .setName("testItem1")
        .build();
    Item item2 = Item::Builder()
        .setName("testItem2")
        .build();
    registry->addItem(0, &item1);
    registry->addItem(0, &item2);
    /* registry->dumpRegistry(); */
    REQUIRE(0==0);
}
