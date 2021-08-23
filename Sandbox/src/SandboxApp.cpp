#include <Papaya.h>

class Sandbox : public Papaya::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

void main()
{
	Sandbox* sandbox = new Sandbox(); // creat on the heap
	sandbox->Run();
	delete sandbox;
}