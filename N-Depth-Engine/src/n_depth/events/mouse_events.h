#pragma once

#include "events.h"
#include <sstream>


namespace ND
{
	class ND_API Mouse_Moved_Event : public Event
	{
	public:
		Mouse_Moved_Event(float x, float y) : m_x_position(x), m_y_position(y) {}

		inline float Get_X() const { return m_x_position; }
		inline float Get_Y() const { return m_y_position; }
		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Mouse moved Event. x = " << m_x_position << ", y = " << m_y_position;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(Event_Mouse | Event_Input);
		EVENT_CLASS_TYPE(Mouse_Moved);

	private:
		float m_x_position, m_y_position;

	};

	class ND_API Mouse_Scrolled_Event : public Event
	{
	public:
		Mouse_Scrolled_Event(float x, float y) : m_x_offset(x), m_y_offset(y) {}

		inline float Get_X() const { return m_x_offset; }
		inline float Get_Y() const { return m_y_offset; }
		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Mouse moved event. x = " << m_x_offset << ", y = " << m_y_offset;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY((Event_Mouse | Event_Input));
		EVENT_CLASS_TYPE(Mouse_Scrolled);

	private:
		float m_x_offset, m_y_offset;

	};


	class ND_API Mouse_Button_Event : public Event
	{
	public:
		inline virtual const char Get_Mouse_Button() const { return m_mouse_code; }

		EVENT_CLASS_CATEGORY((Event_Mouse | Event_Mouse_Button | Event_Input));

	protected:
		Mouse_Button_Event(char mouse_code) : m_mouse_code(mouse_code) {}

		int m_mouse_code;
	};

	class ND_API Mouse_Button_Pressed_Event : public Mouse_Button_Event
	{
	public:
		Mouse_Button_Pressed_Event(int mouse_code) : Mouse_Button_Event(mouse_code) {}
		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << m_mouse_code;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Mouse_Button_Pressed);
	};

	class ND_API Mouse_Button_Released_Event : public Mouse_Button_Event
	{
	public:
		Mouse_Button_Released_Event(int mouse_code) : Mouse_Button_Event(mouse_code) {}
		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << m_mouse_code;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Mouse_Button_Released);
	};
}