#pragma once

// FROM glfw3.h

#define CLOVER_MOUSE_BUTTON_1         0
#define CLOVER_MOUSE_BUTTON_2         1
#define CLOVER_MOUSE_BUTTON_3         2
#define CLOVER_MOUSE_BUTTON_4         3
#define CLOVER_MOUSE_BUTTON_5         4
#define CLOVER_MOUSE_BUTTON_6         5
#define CLOVER_MOUSE_BUTTON_7         6
#define CLOVER_MOUSE_BUTTON_8         7
#define CLOVER_MOUSE_BUTTON_LAST      CLOVER_MOUSE_BUTTON_8
#define CLOVER_MOUSE_BUTTON_LEFT      CLOVER_MOUSE_BUTTON_1
#define CLOVER_MOUSE_BUTTON_RIGHT     CLOVER_MOUSE_BUTTON_2
#define CLOVER_MOUSE_BUTTON_MIDDLE    CLOVER_MOUSE_BUTTON_3

namespace Clover
{
	enum class MouseButton
	{
		_1         =0,
		_2         =1,
		_3         =2,
		_4         =3,
		_5         =4,
		_6         =5,
		_7         =6,
		_8         =7,
		Last      =CLOVER_MOUSE_BUTTON_8,
		Left      =CLOVER_MOUSE_BUTTON_1,
		Right     =CLOVER_MOUSE_BUTTON_2,
		Middle    =CLOVER_MOUSE_BUTTON_3,
	};
}