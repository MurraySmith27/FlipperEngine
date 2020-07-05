#pragma once

#include "Flipper\Core.h"
#include "Flipper\Window.h"
#include "SDl.h"
#include "FlipperEngine.h"

namespace Flipper {


	class WindowsWindow : public Window {

	public:
		
		WindowsWindow(const WindowProps& props);

		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_WindowData.Width; }
		inline unsigned int GetHeight() const override { return m_WindowData.Height; }

		void SetEventCallback(const EventCallbackFn& callback) override { m_WindowData.EventCallback = callback; }

		//void SetVSync(bool enabled) override;
		//bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		SDL_Window* m_Window;

		struct WindowData 
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;

		
	};
}