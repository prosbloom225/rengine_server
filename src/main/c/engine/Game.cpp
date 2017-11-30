#include "Game.h"

BaseMod Game::mods[1];


Game::Game() {
    // TODO - dynamic modloader
    // hardcoding mods for now
    mods[0] = BaseMod();
    for (auto& mod : mods) {
        LOG(DEBUG) << "Loading mod: " << mod.getModName();
    }
    // TODO - pregame menu/etc .. maybe move to main?
    // start the game loop
    lifecycle();


    // clean up
    ItemRegistry::clear();
}
void Game::lifecycle() {
    // preInit
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>PREINIT<<<" << " - " << mod.getModName();
        mod.preInit();
    }
    // init
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>INIT<<<" << " - " << mod.getModName();
        mod.init();
    }
    // postInit
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>POSTINIT<<<" << " - " << mod.getModName();
        mod.postInit();
    }
}
