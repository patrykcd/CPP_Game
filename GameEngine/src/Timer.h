#pragma once

#include <cstdint>

namespace Core {
    class Timer {
    public:
        Timer();

        void Start();

        uint32_t GetTicks();

    private:
        bool started;
        uint32_t tickCount;
    };
}