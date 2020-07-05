#pragma once

#include "Core.h"
#include "Layer.h"
#include "flpch.h"

namespace Flipper {

	class FLIPPER_API LayerStack
	{
	public:
		LayerStack();

		~LayerStack();

		void PushLayer(Layer* layer);

		void PopLayer(Layer* layer);

		void PushOverlay(Layer* layer);

		void PopOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }

	protected:

		std::vector<Layer*>::iterator layer_insert_index;
		
		std::vector<Layer*> layers;
	};

}

