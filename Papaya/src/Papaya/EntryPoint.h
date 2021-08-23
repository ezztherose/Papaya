#pragma once

#ifdef PAPY_PLATFORM_WINDOWS

extern Papaya::Application* Papaya::CreateApplication();

int main(int argc, char** argv)
{
	Papaya::Log::Init();
	PAPY_CORE_WARN("Log initialized");
	int a = 1;
	PAPY_INFO("Client log. var={0}",a);

	auto app = Papaya::CreateApplication();
	app->Run();
	delete app;
}

#endif