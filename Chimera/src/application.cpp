#include "application.h"

#include "applicationevent.h"
namespace Chimera {

Application::Application() {
  mWindow = std::unique_ptr<Window>(Window::CreateWindow());
  mWindow->SetEventCallBack(
      std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

Application::~Application() {}

void Application::OnEvent(Event& event) {
  CM_CORE_TRACE("{0}", event);

  EventDispatcher dispatcher(event);

  dispatcher.Dispatch<WindowCloseEvent>(
      std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

  for (auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); ++it) {
    if (event.Handled) {
      break;
    }
    (*it)->OnEvent(event);
  }
}

void Application::PushLayer(Layer* layer) {
  mLayerStack.PushLayer(layer);
  layer->OnAttach();
}

void Application::PushOverlay(Layer* overlay) {
  mLayerStack.PushOverlay(overlay);
  overlay->OnAttach();
}

void Application::Run() {
  while (mRunning) {
    for (auto it = mLayerStack.begin(); it != mLayerStack.end(); ++it) {
      (*it)->OnUpdate();
    }
    mWindow->OnUpdate();
  }
}

bool Application::OnWindowClose(WindowCloseEvent& event) {
  mRunning = false;
  return true;
}
}; // namespace Chimera
