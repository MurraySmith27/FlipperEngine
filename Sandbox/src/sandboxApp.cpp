#include <FlipperEngine.h>

class Sandbox : public Flipper::Application {


public:
	Sandbox() {


	}

	~Sandbox() {


	}


	void Run() override {
		
	}

	

};



Flipper::Application* Flipper::CreateApplication() {

	return new Sandbox();


}