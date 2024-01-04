#pragma once
#include "application.h"
#include "logger.h"

int main(int argc, char ** argv) {
    Chimera::Logger::Init();

    auto app = Chimera::CreateApplication();
    app->Run();
}