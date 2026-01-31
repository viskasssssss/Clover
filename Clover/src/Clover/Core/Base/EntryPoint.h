#pragma once

#ifdef CLOVER_PLATFORM_WINDOWS

extern Clover::Application* Clover::CreateApplication();

void main(int argc, char** argv)
{
	Clover::Log::Init();

	CV_PROFILE_BEGIN_SESSION("Startup", "CloverProfile-Startup.json");
	auto app = Clover::CreateApplication();
	CV_PROFILE_END_SESSION();

	CV_PROFILE_BEGIN_SESSION("Runtime", "CloverProfile-Runtime.json");
	app->Run();
	CV_PROFILE_END_SESSION();

	CV_PROFILE_BEGIN_SESSION("Shutdown", "CloverProfile-Shutdown.json");
	delete app;
	CV_PROFILE_END_SESSION();
}

#endif