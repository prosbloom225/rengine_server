#include "include/catch.h"
#include "engine/Game.h"

// BEFORE
Game game = Game();

TEST_CASE("Test game constructor", "[game]") {
    REQUIRE(&game != NULL);
};
TEST_CASE("Test mod loader", "[game]") {
    for (auto& mod : game.mods){
        REQUIRE(mod.getModName().empty() == 0);
    }
};

