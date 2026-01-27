#pragma once

#include "Core.h"

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