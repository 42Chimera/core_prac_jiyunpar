#pragma once

#include "applicationevent.h"
#include "pch.h"
#include "window.h"
#include "layerstack.h"
namespace Chimera {
class CHIMERA_API Application {
public:
  Application();
  virtual ~Application();
  void Run();

  void OnEvent(Event& event);

  void PushLayer(Layer* layer);
  void PushOverlay(Layer* overlay);

private:
  virtual bool OnWindowClose(WindowCloseEvent& event);

private:
  std::unique_ptr<Window> mWindow;
  LayerStack mLayerStack;
  bool mRunning = true;
};

extern std::unique_ptr<Application> CreateApplication();
}; // namespace Chimera