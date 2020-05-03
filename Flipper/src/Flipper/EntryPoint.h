#pragma once


#ifdef FLIPPER_PLATFORM_WINDOWS

//extern tells the compiler that this method is defined in annother translation unit.

extern Flipper::Application* Flipper::CreateApplication();
	
int main(int argc, char** argv) {

	std::cout << "Welcome to the Flipper Engine!" << std::endl;

	auto app = Flipper::CreateApplication();

	app->Run();

	delete app;


}


#endif