#pragma once

#ifdef ND_PLATFORM_WINDOWS

extern ND::Application* ND::Create_Application();

int main(int argc, char** argv)
{
	ND::Log::Init();
	
	auto app = ND::Create_Application();
	app->Run();
	delete app;
}
#endif