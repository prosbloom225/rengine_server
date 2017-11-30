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
        signed int TIME_SCALER = 1;
        unsigned int tick;
        void lifecycle();
        void loader();
};


#endif
