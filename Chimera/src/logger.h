#pragma once

#include "pch.h"
#include "spdlog/spdlog.h"

namespace Chimera {
    class CHIMERA_API Logger {
        public:
            static void Init();

            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return sCoreLogger;}
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return sClientLogger;}
        private:
            static std::shared_ptr<spdlog::logger> sCoreLogger;
            static std::shared_ptr<spdlog::logger> sClientLogger;
    };
}