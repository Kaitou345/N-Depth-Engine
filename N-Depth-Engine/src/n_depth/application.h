#pragma once
#include "core.h"
namespace nd
{
	class ND_API application
	{
	public: 
		application();
		virtual ~application();
		void run();
	};

	// To be defined in client
	application* create_application();
}

