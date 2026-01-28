#pragma once

#include "Core.h"

#include "Window.h"
#include "Clover/LayerStack.h"
#include "Clover/Events/Event.h"
#include "Clover/Events/ApplicationEvent.h"


namespace Clover
{
	class CLOVER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Defined in CLIENT
	Application* CreateApplication();
}