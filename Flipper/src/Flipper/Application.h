#pragma once

#include "Core.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"


namespace Flipper {
	class FLIPPER_API Application
	{
	public:
		Application();

		virtual ~Application();


		virtual void Run();

		void PushLayer(Layer* layer);

		void PushOverlay(Layer* layer);

		void OnEvent(SDL_Event e);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack layer_stack;
		bool m_Running = true;
	};
	
	//TO BE DEFINED IN THE CLIENT
	Application* CreateApplication();
}
