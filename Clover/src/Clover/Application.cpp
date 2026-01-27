#include "cvpch.h"
#include "Application.h"

#include "Clover/Events/ApplicationEvent.h"
#include "Clover/Log.h"

namespace Clover
{
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CLOVER_TRACE("{0}", e.ToString());

		while (true);
	}
}