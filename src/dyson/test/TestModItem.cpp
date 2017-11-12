
#include "include/catch.h"
#include "src/dyson/item/ModItem.h"


TEST_CASE("Test ModItem constructor", "[moditem]") {
    ModItem *item0  = new ModItem("mod", "testModItem0", 1.0);

    // require all properties here
    REQUIRE(strcmp(item0->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item0->getModName(), "mod") == 0);
    REQUIRE(item0->getCVal() == 1.0);

}

TEST_CASE("Test ModItem builder defaults", "[moditem]") {
    ModItem item = ModItem::Builder()
        .build();
    REQUIRE(strcmp(item.getModName(), "dyson") == 0);
    REQUIRE(strcmp(item.getName(), "null") == 0);
    REQUIRE(item.getCVal() == 0.0);
}

TEST_CASE("Test ModItem builder properties", "[moditem]") {
    ModItem item = ModItem::Builder()
        .setName("testModItem1")
        .setCVal(2.0)
        .build();
    REQUIRE(strcmp(item.getModName(), "dyson") == 0);
    REQUIRE(strcmp(item.getName(), "testModItem1") == 0);
    REQUIRE(item.getCVal() == 2.0);
}
