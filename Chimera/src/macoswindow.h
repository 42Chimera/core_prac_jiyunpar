#pragma once

#include "GLFW/glfw3.h"
#include "pch.h"
#include "window.h"

namespace Chimera {
class MacOSWindow : public Window {
public:
  MacOSWindow(const WindowProps &props);
  virtual ~MacOSWindow();

  void OnUpdate() override;

  inline uint32_t GetWidth() const override { return mData.Width; }
  inline uint32_t GetHeight() const override { return mData.Height; }

  inline void SetEventCallBack(const EventCallBackFunction &callBack) override {
    mData.EventCallBack = callBack;
  }
  void SetVSync(bool enabled) override;
  bool IsVSync() const override;

private:
  void Init(const WindowProps &props);
  void Shutdown();

  GLFWwindow *mWindow;
  struct WindowData {
    std::string Title;
    uint32_t Width, Height;
    bool VSync;

    EventCallBackFunction EventCallBack;
  };

  WindowData mData;
};
} // namespace Chimera