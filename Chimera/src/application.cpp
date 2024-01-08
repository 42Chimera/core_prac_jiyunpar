#include "application.h"

namespace Chimera {

    Application::Application() {
        mWindow = std::unique_ptr<Window>(Window::CreateWindow());
    }

    Application::~Application() {}

    void Application::Run() {
        while(mRunning) {
            mWindow->OnUpdate();
        }
    }
};
