#include <FlipperEngine.h>

class Sandbox : public Flipper::Application {


public:
	Sandbox() {


	}

	~Sandbox() {


	}


};



Flipper::Application* Flipper::CreateApplication() {

	return new Sandbox();


}