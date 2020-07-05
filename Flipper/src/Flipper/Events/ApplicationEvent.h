#include "Event.h"

namespace Flipper {
	
	class FLIPPER_API WindowResizeEvent : public Event {
	
	public:

		WindowResizeEvent(unsigned int w, unsigned int h) : m_Width(w), m_Height(h) {}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "x" << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication )

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class FLIPPER_API WindowCloseEvent : public Event {


	public:
		WindowCloseEvent() {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FLIPPER_API AppTickEvent : public Event {


	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FLIPPER_API AppUpdateEvent : public Event {


	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FLIPPER_API AppRenderEvent : public Event {


	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}