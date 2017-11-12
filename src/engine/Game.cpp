#include "Game.h"

Game::Game() {
    // TODO - dynamic modloader
    // hardcoding mods for now
    mods[0] = new BaseMod();
    lifecycle();
}
void Game::lifecycle() {
    for (auto& mod : mods) {
        LOG(DEBUG) << "Loading mod: " << mod->getModName();
    }
}
