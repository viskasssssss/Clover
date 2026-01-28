#include <Clover.h>

#include <imgui/imgui.h>

class ExampleLayer : public Clover::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Tab))
			CLOVER_INFO("Tab is pressed");
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("This is a test");
		ImGui::End();
	}

	void OnEvent(Clover::Event& event) override
	{
		if (event.GetEventType() == Clover::EventType::KeyPressed)
		{
			Clover::KeyPressedEvent& e = (Clover::KeyPressedEvent&)event;
			CLOVER_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Clover::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Clover::Application* Clover::CreateApplication()
{
	return new Sandbox();
}