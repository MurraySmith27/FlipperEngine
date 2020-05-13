#pragma once
#include "flpch.h"

#ifdef FLIPPER_PLATFORM_WINDOWS

//extern tells the compiler that this method is defined in annother translation unit.

extern Flipper::Application* Flipper::CreateApplication();
	
int main(int argc, char** argv) {

	Flipper::Log::Init();

	FLIPPER_CORE_INFO("Welcome to the Flipper Engine");

	auto app = Flipper::CreateApplication();

	app->Run();

	delete app;

	return 0;
}


#endif