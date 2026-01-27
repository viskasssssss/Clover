#pragma once

#ifdef CLOVER_PLATFORM_WINDOWS

extern Clover::Application* Clover::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Clover::CreateApplication();
	app->Run();
	delete app;
}

#endif