#pragma once
#include "core.h"
namespace ND
{
	class ND_API Application
	{
	public: 
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* Create_Application();
}

