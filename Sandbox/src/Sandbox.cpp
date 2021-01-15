#include <nd.h>

class Sandbox : public ND::Application
{
public:
	Sandbox() 
	{
	}
	~Sandbox()
	{
	}
};

ND::Application* ND::Create_Application()
{	
	return new Sandbox();
}