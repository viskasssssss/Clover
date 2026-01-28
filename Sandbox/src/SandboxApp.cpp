#include <Clover.h>

class ExampleLayer : public Clover::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		//CLOVER_INFO("ExampleLayer::OnUpdate");

		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Tab))
			CLOVER_INFO("Tab is pressed");
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
		PushOverlay(new Clover::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Clover::Application* Clover::CreateApplication()
{
	return new Sandbox();
}