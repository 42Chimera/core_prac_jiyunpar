#pragma once

#include "pch.h"
#include "spdlog/spdlog.h"

namespace Chimera {
class CHIMERA_API Logger {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

   private:
    static std::shared_ptr<spdlog::logger> sCoreLogger;
    static std::shared_ptr<spdlog::logger> sClientLogger;
};
}  // namespace Chimera

// Core Logger Macro
#define CM_CORE_TRACE(...) ::Chimera::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CM_CORE_INFO(...) ::Chimera::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CM_CORE_WARN(...) ::Chimera::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CM_CORE_ERROR(...) ::Chimera::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CM_CORE_FATAL(...) ::Chimera::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logger Macro
#define CM_CLIENT_TRACE(...) ::Chimera::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define CM_CLIENT_INFO(...) ::Chimera::Logger::GetClientLogger()->info(__VA_ARGS__)
#define CM_CLIENT_WARN(...) ::Chimera::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define CM_CLIENT_ERROR(...) ::Chimera::Logger::GetClientLogger()->error(__VA_ARGS__)
#define CM_CLIENT_FATAL(...) ::Chimera::Logger::GetClientLogger()->fatal(__VA_ARGS__)