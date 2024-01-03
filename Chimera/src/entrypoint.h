#pragma once
#include "application.h"

int main(int argc, char ** argv) {
    auto app = Chimera::CreateApplication();
    app->Run();
}