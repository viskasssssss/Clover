#include <Clover.h>

class Sandbox : public Clover::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Clover::Application* Clover::CreateApplication()
{
	return new Sandbox();
}