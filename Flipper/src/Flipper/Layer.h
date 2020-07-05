#pragma once

#include "Core.h"

namespace Flipper {
	class FLIPPER_API Layer
	{
	public:
		Layer(const std::string& name = "Default Layer");
		//virtual deconstructor 
		//we're extending to create layers.
		virtual ~Layer();

		//Called when a layer is pushed to the LayerStack
		virtual void OnAttach() {}
		//Called when a layer is removed from the LayerStack
		virtual void OnDetach() {}
		//Called in the update function. Manages Game logic for layers.
		virtual void OnUpdate(){}
		//Called when an event gets sent to the layer. This function does not have to handle the event, instead it can pass it down.
		virtual void OnEvent(SDL_Event& event){}

		inline const std::string& GetName() const { return debug_name; }
	protected:
		//The name of the layer for debug purposes.
		std::string debug_name;
	};
}

