#include "Event.h"

namespace Flipper {


	class FLIPPER_API KeyEvent : public Event {


	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		int m_KeyCode;
		//protected constructor? Why?
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
	};


	class FLIPPER_API KeyPressedEvent : public KeyEvent {

	public:
		//Calling the KeyEvent constructor from the variable assignment section.
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeated " << m_RepeatCount << " times)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:

		int m_RepeatCount;
	};

	class FLIPPER_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


}