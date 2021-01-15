#pragma once

#include "events.h"
#include <sstream>

namespace ND
{
	class ND_API Key_Event : public Event
	{
	public:
		inline int Get_Key_Code() const { return m_key_code; }
		EVENT_CLASS_CATEGORY(Event_Keyboard | Event_Input);

	protected:
		Key_Event(int key_code) : m_key_code(key_code) {}
		int m_key_code;
	};

	class ND_API Key_Pressed_Event : public Key_Event
	{
	public:
		Key_Pressed_Event(int key_code, int repeat_count) 
			: Key_Event(key_code), m_repeat_count(repeat_count) {}

		inline int Get_Repeat_Count() const { return m_repeat_count; }

		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Key pressed Event = " << m_key_code << ", repeated = " << m_repeat_count;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Key_Pressed);

	private:
		int m_repeat_count;
	};

	class ND_API Key_Released_Event : public Key_Event
	{
	public:
		Key_Released_Event(int key_code) : Key_Event(key_code) {}

		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Key pressed Event = " << m_key_code;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Key_Released);

	};
}

