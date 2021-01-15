#pragma once

#include "events.h"
#include <sstream>

namespace ND
{
	class ND_API Window_Close_event : public Event
	{
	public:
		Window_Close_event() {}
		EVENT_CLASS_TYPE(Window_Close);
		EVENT_CLASS_CATEGORY(Event_App)
	};

	class ND_API Window_Resize_Event : public Event
	{
	public:
		Window_Resize_Event(unsigned int height, unsigned int width) 
		: m_height(height), m_width(width)	{}

		inline unsigned int Get_Height() { return m_height; }
		inline unsigned int Get_Width() { return m_width; }

		std::string To_String() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event. Height : " << m_height << " Width : " << m_width;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Window_Resize);
		EVENT_CLASS_CATEGORY(Event_App);

	private:
		unsigned int m_height, m_width;
	};

	class ND_API App_Tick_Event : public Event
	{
	public:
		App_Tick_Event() {}

		EVENT_CLASS_TYPE(App_Tick);
		EVENT_CLASS_CATEGORY(Event_App);
	};

	class ND_API App_Update_Event : public Event
	{
	public:
		App_Update_Event() {}

		EVENT_CLASS_TYPE(App_Update);
		EVENT_CLASS_CATEGORY(Event_App);
	};

	class ND_API App_Render_Event : public Event
	{
	public:
		App_Render_Event() {}

		EVENT_CLASS_TYPE(App_Render);
		EVENT_CLASS_CATEGORY(Event_App);
	};
}

