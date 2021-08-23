#pragma once

#ifdef PAPY_PLATFORM_WINDOWS

extern Papaya::Application* Papaya::CreateApplication();

int main(int argc, char** argv)
{
	Papaya::Log::Init();
	//Papaya::Log::GetCoreLogger()->warn("Log initialized");
	PAPY_CORE_WARN("Log initialized");
	//Papaya::Log::GetClientLogger()->info("Client log");
	int a = 1;
	PAPY_INFO("Client log. var={0}",a);

	auto app = Papaya::CreateApplication();
	//Sandbox* sandbox = new Sandbox(); // creat on the heap
	app->Run();
	delete app;
}

#endif