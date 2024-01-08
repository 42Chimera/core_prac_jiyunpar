#pragma once

#include "pch.h"
#include "window.h"
namespace Chimera {
    class CHIMERA_API Application {
        public:
            Application();
            virtual ~Application();
            virtual void Run();
        private:
            std::unique_ptr<Window> mWindow;
            bool mRunning = true;
    };

    extern std::unique_ptr<Application> CreateApplication();
};