#include "Game.h"

BaseMod Game::mods[1];


Game::Game() {
    // TODO - dynamic modloader
    // hardcoding mods for now
    mods[0] = BaseMod();
    for (auto& mod : mods) {
        LOG(DEBUG) << "Loading mod: " << mod.getModName();
    }
    loader();
    // TODO - pregame menu/etc .. maybe move to main?
    // start the game loop
    lifecycle();


    // clean up
    ItemRegistry::clear();
}
void Game::loader() {
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

void Game::lifecycle() {
    // main game loop
    while (true){
        tick++;
        if (tick%100)
            LOG(INFO)<<tick;
        int a;
        std::cin >> a;
        std::cout << a;

        // sanity
        if (tick > 20)
            break;
    };
}
