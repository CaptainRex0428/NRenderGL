#include "Trace/Trace.h"
#include "ScrewExtend.h"

#include "Window/WindowsWindow.h"

namespace Element
{
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {}

	void WindowsWindow::Init(const WindowProps& props)
	{
		// SCREW_EXTEND_TIMER_TRACE_NSTORE();

		m_Data.Title = props.m_Title;
		m_Data.Width = props.m_Width;
		m_Data.Height = props.m_Height;
		
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			s_GLFWInitialized = success;
		}

		m_Window = glfwCreateWindow((int)props.m_Width, (int)props.m_Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}
}
