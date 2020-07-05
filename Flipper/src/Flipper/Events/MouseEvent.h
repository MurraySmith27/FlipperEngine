#include "Event.h"


namespace Flipper {

	class FLIPPER_API MouseMovedEvent : public Event {

	;

	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }


		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class FLIPPER_API MouseScrolledEvent : public Event {


	public:
		MouseScrolledEvent(float offset_x, float offset_y)
			: m_XOffset(offset_x), m_YOffset(offset_y) {}
		
		inline float GetXOffset()const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "MouseScrolledEvent " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		
	private:
		float m_XOffset, m_YOffset;


	};

	class FLIPPER_API MouseButtonEvent : public Event {

	public:

		inline int GetMouseButton() { return m_ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : m_ButtonCode(button) {}

		int m_ButtonCode;
	};


	class FLIPPER_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_ButtonCode;
			return ss.str();
		}


		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class FLIPPER_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:

		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}