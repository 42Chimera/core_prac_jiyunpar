#include "application.h"

#include "applicationevent.h"
namespace Chimera {

Application::Application() {
  mWindow = std::unique_ptr<Window>(Window::CreateWindow());
  mWindow->SetEventCallBack(
      std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

Application::~Application() {}

void Application::OnEvent(Event &event) {
  CM_CORE_TRACE("{0}", event);

  EventDispatcher dispatcher(event);

  dispatcher.Dispatch<WindowCloseEvent>(
      std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
}

void Application::Run() {
  while (mRunning) {
    mWindow->OnUpdate();
  }
}

bool Application::OnWindowClose(WindowCloseEvent &event) {
  mRunning = false;
  return true;
}
}; // namespace Chimera
