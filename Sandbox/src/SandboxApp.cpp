#include <Clover.h>

class ExampleLayer : public Clover::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		CLOVER_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Clover::Event& event) override
	{
		CLOVER_TRACE("{0}", event.ToString());
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