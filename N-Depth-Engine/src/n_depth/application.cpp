#include "application.h"
#include "events/events.h"
#include "n_depth/events/events.h"
#include "n_depth/events/application_events.h"
#include "n_depth/events/key_events.h"
#include "n_depth/events/mouse_events.h"
#include "log.h"

namespace ND
{

	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		using namespace ND;
		Mouse_Button_Pressed_Event a(1);
		ND_ERROR("Welcome to the NDEngine. Please Read the docs on how to use it");
		ND_ERROR(a);
		while (true);
	}
}

