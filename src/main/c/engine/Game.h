#ifndef GAME_H
#define GAME_H

#include "engine/registry/ItemRegistry.h"
#include "engine/base/BaseMod.h"

class Game {
    public:
        Game();
        static ItemRegistry registry;
        static BaseMod mods[1];

    private:
        void lifecycle();
};


#endif
