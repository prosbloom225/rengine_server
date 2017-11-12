#ifndef GAME_H
#define GAME_H

#include "src/engine/registry/ItemRegistry.h"
#include "src/engine/base/BaseMod.h"

class Game {
    public:
        Game();
        static ItemRegistry registry;
        BaseMod *mods[1];

    private:
        void lifecycle();
};


#endif
