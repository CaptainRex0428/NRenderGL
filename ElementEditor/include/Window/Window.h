#pragma once

#include <functional>
#include <string>

#include "EE_API.h"
#include "Event/Event.h"

namespace Element 
{
	struct ENGINE_API WindowProps
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		WindowProps(const std::string & title = "ElementEngine", 
			unsigned int width = 1280, 
			unsigned int height = 720)
			:m_Title(title),m_Width(width),m_Height(height)
		{}
	};

	class ENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(ScrewExtend::Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window * Create(const WindowProps & props = WindowProps());
		
	protected:
		bool s_GLFWInitialized = false;
	};
}