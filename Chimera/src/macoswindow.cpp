#include "macoswindow.h"

namespace Chimera {

static bool sGLFWInitialized = false;
Window* Window::CreateWindow(const WindowProps& props) {
    return new MacOSWindow(props);
}

MacOSWindow::~MacOSWindow() {
    Shutdown();
}

MacOSWindow::MacOSWindow(const WindowProps& props) {
    Init(props);
}

void MacOSWindow::Init(const WindowProps& props) {
    mData.Title = props.Title;
    mData.Width = props.Width;
    mData.Height = props.Height;
}
void MacOSWindow::Shutdown() {
    glfwDestroyWindow(mWindow);
}
}  // namespace Chimera