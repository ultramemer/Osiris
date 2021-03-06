#pragma once

#include "Entity.h"
#include "EntityList.h"
#include "../Interfaces.h"

struct GlobalVars {
    const float realtime;
    const int framecount;
    const std::byte pad[8];
    const float currenttime;
    const float frametime;
    const int maxClients;
    const int tickCount;
    const float intervalPerTick;

    constexpr float serverTime() noexcept
    {
        return interfaces.entityList->getEntity(interfaces.engine->getLocalPlayer())->getProperty<int>("m_nTickBase") * intervalPerTick;
    }
};
