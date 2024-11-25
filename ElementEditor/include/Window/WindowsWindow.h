#pragma once

#include "GLFW/glfw3.h"

#include "EE_API.h"
#include "Window/Window.h"

namespace Element {
	class ENGINE_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps & props);
		virtual ~WindowsWindow();

		// Window API
		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; };
		unsigned int GetHeight() const override { return m_Data.Height; };

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		virtual void SetVSync(bool enabled) override { m_Data.VSync = enabled; };
		virtual bool isVSync() const override { return m_Data.VSync; };

	protected:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}