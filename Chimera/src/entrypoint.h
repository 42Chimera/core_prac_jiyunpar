#pragma once
#include "application.h"
#include "logger.h"

int main(int argc, char **argv) {
  Chimera::Logger::Init();
  CM_CORE_INFO("Init Engine");
  CM_CLIENT_INFO("THIS IS APP");
  auto app = Chimera::CreateApplication();
  app->Run();
}