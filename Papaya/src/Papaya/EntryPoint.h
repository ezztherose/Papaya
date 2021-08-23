#pragma once

#ifdef PAPY_PLATFORM_WINDOWS

extern Papaya::Application* Papaya::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Papaya::CreateApplication();
	//Sandbox* sandbox = new Sandbox(); // creat on the heap
	app->Run();
	delete app;
}

#endif