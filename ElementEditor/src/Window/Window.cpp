#include "Window/Window.h"
#include "Window/WindowsWindow.h"

namespace Element {
    Window* Window::Create(const WindowProps& props)
    {
#ifdef _WINDOWS
        return new WindowsWindow(props);
#endif
    }
}