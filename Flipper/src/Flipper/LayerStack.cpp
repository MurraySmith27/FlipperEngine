#include "flpch.h"
#include "LayerStack.h"

namespace Flipper {

	LayerStack::LayerStack() {
		LayerStack::layer_insert_index = layers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* l : LayerStack::layers) {
			delete l;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {

		layer_insert_index = layers.emplace(layer_insert_index, layer);
	}

	void LayerStack::PopLayer(Layer* layer) {

		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
			layer_insert_index--;
		}

	}

	void LayerStack::PushOverlay(Layer* layer) {
		layers.emplace_back(layer);
	}

	void LayerStack::PopOverlay(Layer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
		}
	}



}
