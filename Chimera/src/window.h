#pragma once

#include "event.h"
#include "pch.h"

namespace Chimera {
struct WindowProps {
    WindowProps(const std::string& title = "Chimera Engine", uint32_t width = 1280, uint32_t height = 720)
        : Title(title), Width(width), Height(height) {}
    std::string Title;
    uint32_t Width;
    uint32_t Height;
};

class CHIMERA_API Window {
   public:
    using EventCallBackFunction = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;

    virtual void SetEventCallBack(const EventCallBackFunction& callBack) = 0;
    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    static Window* CreateWindow(const WindowProps& props = WindowProps());
};
}  // namespace Chimera