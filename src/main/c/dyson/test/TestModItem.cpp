
#include "include/catch.h"
#include "dyson/item/ModItem.h"

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
    LOG(INFO) << item;
}
