#pragma once

#include "pch.h"
#include "window.h"
#include "applicationevent.h"
namespace Chimera {
class CHIMERA_API Application {
   public:
    Application();
    virtual ~Application();
    virtual void Run();

    virtual void OnEvent(Event& event);

    virtual bool OnWindowClose(WindowCloseEvent& event);

   private:
    std::unique_ptr<Window> mWindow;
    bool mRunning = true;
};

extern std::unique_ptr<Application> CreateApplication();
};  // namespace Chimera