#include <Clover.h>
#include <Clover/Core/Base/EntryPoint.h>

#include <imgui/imgui.h>

#include "Sandbox2D.h"

class Sandbox : public Clover::Application
{
public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Clover::Application* Clover::CreateApplication()
{
	return new Sandbox();
}