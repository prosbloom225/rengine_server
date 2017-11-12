
#include "include/catch.h"
#include "src/dyson/item/ModItem.h"


TEST_CASE("Test basic ModItem", "[moditem]") {
    ModItem item = ModItem::Builder()
            .setName("testModItem1")
            .setCval(1.0)
            .build();

    // require all properties here
    REQUIRE(strcmp(item.getName(), "testModItem1") == 0);
    REQUIRE(item.getCVal() == 0);
}
