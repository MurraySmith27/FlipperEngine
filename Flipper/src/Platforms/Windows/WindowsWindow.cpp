#include "WindowsWindow.h"

namespace Flipper {

	static bool s_SDLInitialized = false;

	Window* Window::Create(const WindowProps& props = WindowProps()) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_WindowData.Height = props.Height;
		m_WindowData.Width = props.Width;

		m_WindowData.Title = props.Title;

		m_WindowData.VSync = false;

		m_WindowData.EventCallback = NULL;

		FLIPPER_CORE_INFO("Creating window {0} ({1}x{2})", props.Title, props.Width, props.Height);

		if (!s_SDLInitialized) {
			int success = SDL_Init(SDL_INIT_VIDEO);
			FLIPPER_CORE_ASSERT(success == 0, "Could not initialize SDL Video.");
			s_SDLInitialized = true;
		}

		m_Window = SDL_CreateWindow(m_WindowData.Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)props.Width, (int)props.Height, SDL_WINDOW_SHOWN);
		FLIPPER_CORE_ASSERT(m_Window != NULL, "Failed to Create SDL_Window object");

		
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Shutdown() {
		SDL_DestroyWindow(m_Window);
		delete m_Window;
	}

	void WindowsWindow::OnUpdate() {

		//Might have to come back to this later to do some form of window event polling.
	
	}

	unsigned int WindowsWindow::GetWidth() const {
		return m_WindowData.Width;
	}

	unsigned int WindowsWindow::GetHeight() const {
		return m_WindowData.Height;
	}

	void WindowsWindow::SetEventCallback(const Window::EventCallbackFn&) {

	}

	/*void WindowsWindow::SetVSync(bool enabled) {

		if (enabled)


	}

	bool WindowsWindow::IsVSync() const {


	}*/
}