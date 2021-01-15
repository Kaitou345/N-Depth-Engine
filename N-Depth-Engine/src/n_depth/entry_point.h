#pragma once
#include "events/key_events.h"

#ifdef ND_PLATFORM_WINDOWS
extern ND::Application* ND::Create_Application();

int main(int argc, char** argv)
{
	ND::Log::Init();
	auto app = ND::Create_Application();
	using namespace ND;
	ND_ERROR("Welcome to the NDEngine. Please Read the docs on how to use it");

	app->Run();
	delete app;
}
#endif