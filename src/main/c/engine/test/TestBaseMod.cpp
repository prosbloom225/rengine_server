#include "include/catch.h"
#include "engine/base/Items.h"

TEST_CASE("Test base mod item loading","[base]") {
    /* ItemRegistry::clear(); */
    Items::loadItems();
    ItemRegistry::dumpRegistry();
};
