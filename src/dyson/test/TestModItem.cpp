
#include "include/catch.h"
#include "src/dyson/item/ModItem.h"


TEST_CASE("Test basic ModItem", "[moditem]") {
    ModItem *item = new ModItem("testModItem1", 0);

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getCVal() == 0);
}
