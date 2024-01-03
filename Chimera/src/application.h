#pragma once

#include "core.h"
#include <memory>

namespace Chimera {
    class CHIMERA_API Application {
        public:
            Application();
            virtual ~Application();
            virtual void Run();
    };

    extern std::unique_ptr<Application> CreateApplication();
};