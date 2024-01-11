
#include "chimera.h"

class ExampleLayer : public Chimera::Layer {
public:
  ExampleLayer() : Layer("ExampleLayer") {}

  void OnUpdate() override { CM_CLIENT_INFO("ExampleLayer::update()"); }

  void OnEvent(Chimera::Event& event) override {
    CM_CLIENT_TRACE("{0}", event);
  }
};
class App : public Chimera::Application {
public:
  App() { PushLayer(new ExampleLayer()); };
  ~App(){};
};

std::unique_ptr<Chimera::Application> Chimera::CreateApplication() {
  return std::make_unique<App>();
}