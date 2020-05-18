#include <FlipperEngine.h>

class Sandbox : public Flipper::Application {


public:
	Sandbox() {


	}

	~Sandbox() {


	}


	void Run() override {
		//This is the first thing that gets called.
		FLIPPER_INFO("Running from client");

		Flipper::Renderer* my_renderer = new Flipper::Renderer("My Window", 600, 600);


		my_renderer->texture_stack_push("example_image", "hello.bmp", 300, 300);

		bool running = true; 

		SDL_Event e;

		while (running) {
			//move through the entire event queue
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					running = false;
				}

				my_renderer->update();

			}
		}
	}

};



Flipper::Application* Flipper::CreateApplication() {

	return new Sandbox();


}