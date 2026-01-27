#pragma once

#include "Core.h"

#include "Clover/Events/Event.h"
#include "Clover/Events/ApplicationEvent.h"

#include "Window.h"

namespace Clover
{
	class CLOVER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined in CLIENT
	Application* CreateApplication();
}