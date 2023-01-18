#include "Timer.h"
#include <SDL.h>

namespace Core {
    Timer::Timer() {
        tickCount = 0;
        started = false;
    }

    void Timer::Start() {
        tickCount = SDL_GetTicks();
        started = true;
    }

    Uint32 Timer::GetTicks() {
        if (!started) {
            return 0;
        }

        return SDL_GetTicks() - tickCount;
    }
}