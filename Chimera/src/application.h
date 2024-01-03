#pragma once

#include "core.h"

namespace Chimera {
    class CHIMERA_API Application {
        public:
            Application();
            virtual ~Application();
            virtual void Run();
    };

};