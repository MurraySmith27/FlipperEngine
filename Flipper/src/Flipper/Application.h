#pragma once

#include "Core.h"


namespace Flipper {
	class FLIPPER_API Application
	{
	public:
		Application();

		virtual ~Application();


		void Run();

	};
	
	//TO BE DEFINED IN THE CLIENT
	Application* CreateApplication();
}
