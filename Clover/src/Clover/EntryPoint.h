#pragma once

#ifdef CLOVER_PLATFORM_WINDOWS

extern Clover::Application* Clover::CreateApplication();

void main(int argc, char** argv)
{
	Clover::Log::Init();
	CLOVER_CORE_WARN("Initialized Log");
	const char* a = "lol";
	CLOVER_TRACE("Sup {0}", a);

	auto app = Clover::CreateApplication();
	app->Run();
	delete app;
}

#endif