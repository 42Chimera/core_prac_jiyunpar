#include "logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Chimera {
std::shared_ptr<spdlog::logger> Logger::sCoreLogger;
std::shared_ptr<spdlog::logger> Logger::sClientLogger;

void Logger::Init() {
  spdlog::set_pattern("%^[%T] %n: %v%$");

  sCoreLogger = spdlog::stdout_color_mt("Chimera");
  sCoreLogger->set_level(spdlog::level::trace);

  sClientLogger = spdlog::stdout_color_mt("App");
  sClientLogger->set_level(spdlog::level::trace);
}
} // namespace Chimera