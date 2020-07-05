#include "flpch.h"
#include "Application.h"
#include "Render.h"
#include "Log.h"

#include "Events/ApplicationEvent.h"


namespace Flipper {
	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());

	}


	Application::~Application() {


	}

	void Application::Run() {
		FLIPPER_CORE_INFO("Reached run method from Application");

		while (m_Running) {
			
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(SDL_Event e) {
		for (auto it = layer_stack.end(); it != layer_stack.begin();) {
			//This requires that the event be handled somewhere.
			(*--it)->OnEvent(e);
			//check to see if the event queue is empty, and if not, handle the events.
			if (SDL_PollEvent(&e) == 0) {
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer) {
		Application::layer_stack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		Application::layer_stack.PushOverlay(layer);
	}
}