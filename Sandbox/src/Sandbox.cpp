#include <nd.h>

class Sandbox : public nd::application
{
public:
	Sandbox() 
	{
	}
	~Sandbox()
	{
	}
};

nd::application* nd::create_application()
{	
	return new Sandbox();
}