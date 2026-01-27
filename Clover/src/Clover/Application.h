#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Clover
{
	class CLOVER_API Application
	{
	public:
		virtual ~Application();

		void Run();
	};

	// Defined in CLIENT
	Application* CreateApplication();
}