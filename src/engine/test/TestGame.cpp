#include "include/catch.h"
#include "src/engine/Game.h"

TEST_CASE("Test game constructor", "[game]") {
    Game game = Game();
    REQUIRE(&game != NULL);
};
TEST_CASE("Test mod loader", "[game]") {
    Game game = Game();
    for (auto& mod : game.mods){
        REQUIRE(mod->getModName().empty() == 0);
    }
};

