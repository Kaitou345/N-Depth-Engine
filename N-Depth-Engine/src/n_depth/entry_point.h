#pragma once
#ifdef ND_PLATFORM_WINDOWS

extern nd::application* nd::create_application();

int main(int argc, char** argv)
{

	nd::log::init();
	ND_WARN("Helo = {0}", 5);

	auto app = nd::create_application();
	app->run();
	delete app;
}
#endif
