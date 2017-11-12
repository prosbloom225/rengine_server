
#include "include/catch.h"
#include "src/dyson/item/ModItem.h"


TEST_CASE("Test basic ModItem", "[moditem]") {
    ModItem *item0  = new ModItem("mod", "testModItem0", 1.0);

    /*
    Item item = ModItem::Builder()
            .setName("testModItem1")
            .setCval(1.0)
            .build();
            */

    // require all properties here
    REQUIRE(strcmp(item0->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item0->getModName(), "mod") == 0);
    REQUIRE(item0->getCVal() == 1.0);

    /* REQUIRE(strcmp(item.getName(), "testModItem1") == 0); */
    /* REQUIRE(item.getCVal() == 1.0); */
}
