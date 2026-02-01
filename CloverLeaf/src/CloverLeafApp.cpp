#include <Clover.h>
#include <Clover/Core/Base/EntryPoint.h>

#include <imgui/imgui.h>

#include "EditorLayer.h"

namespace Clover
{
	class CloverLeaf : public Application
	{
	public:
		CloverLeaf()
			: Application("Clover Leaf")
		{
			PushLayer(new EditorLayer());
		}

		~CloverLeaf()
		{

		}
	};

	Application* CreateApplication()
	{
		return new CloverLeaf();
	}
}