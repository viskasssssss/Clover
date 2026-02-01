#pragma once

#include "Clover/Core/Core.h"
#include "Clover/Core/Input/KeyCodes.h"
#include "Clover/Core/Input/MouseButtonCodes.h"

namespace Clover
{
	class CLOVER_API Input
	{
	public:
		static bool IsKeyPressed(int keycode);
		static bool IsKeyPressed(KeyCode keycode) { return IsKeyPressed((int)keycode); }

		static bool IsMouseButtonPressed(int button);
		static bool IsMouseButtonPressed(MouseButton button) { return IsMouseButtonPressed((int)button); }
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}