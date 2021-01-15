#pragma once

#include "n_depth/core.h"
#include <string>

namespace ND
{
	enum class Event_Type
	{
		None = 0,
		Window_Close, Window_Resize, Window_Moved, Window_Focus, Window_Lost_Focus,
		App_Tick, App_Render, App_Update,
		Key_Pressed, Key_Released,
		Mouse_Button_Pressed, Mouse_Button_Released, Mouse_Scrolled, Mouse_Moved
	};

	enum Event_Category
	{
		None = 0,
		Event_App = BIT(0),
		Event_Input = BIT(1),
		Event_Keyboard = BIT(2),
		Event_Mouse = BIT(3),
		Event_Mouse_Button = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static Event_Type Get_Static_Type() { return Event_Type::##type; }\
								virtual Event_Type Get_Event_Type() const override { return Get_Static_Type(); }\
								virtual const char* Get_Name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int Get_Event_Category_Flags() const override { return category; }

	class ND_API Event
	{
	public:
		virtual Event_Type Get_Event_Type() const = 0;
		virtual const char* Get_Name() const = 0;
		virtual int Get_Event_Category_Flags() const = 0;
		virtual std::string To_String() const { return std::string(Get_Name()); }

		inline bool Is_In_Category(Event_Category Category)
		{
			return (Get_Event_Category_Flags() & (int)Category);
		}

	protected:
		bool m_Handled = false;
	};

};