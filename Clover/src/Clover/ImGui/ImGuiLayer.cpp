#include "cvpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Clover/Core/Application.h"
#include "Clover/Core/KeyCodes.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Clover
{
	static ImGuiKey ToImGuiKey(int keycode)
	{
        switch (keycode)
        {
        case CLOVER_KEY_TAB: return ImGuiKey_Tab;
        case CLOVER_KEY_LEFT: return ImGuiKey_LeftArrow;
        case CLOVER_KEY_RIGHT: return ImGuiKey_RightArrow;
        case CLOVER_KEY_UP: return ImGuiKey_UpArrow;
        case CLOVER_KEY_DOWN: return ImGuiKey_DownArrow;
        case CLOVER_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case CLOVER_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case CLOVER_KEY_HOME: return ImGuiKey_Home;
        case CLOVER_KEY_END: return ImGuiKey_End;
        case CLOVER_KEY_INSERT: return ImGuiKey_Insert;
        case CLOVER_KEY_DELETE: return ImGuiKey_Delete;
        case CLOVER_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case CLOVER_KEY_SPACE: return ImGuiKey_Space;
        case CLOVER_KEY_ENTER: return ImGuiKey_Enter;
        case CLOVER_KEY_ESCAPE: return ImGuiKey_Escape;
        case CLOVER_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case CLOVER_KEY_COMMA: return ImGuiKey_Comma;
        case CLOVER_KEY_MINUS: return ImGuiKey_Minus;
        case CLOVER_KEY_PERIOD: return ImGuiKey_Period;
        case CLOVER_KEY_SLASH: return ImGuiKey_Slash;
        case CLOVER_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case CLOVER_KEY_EQUAL: return ImGuiKey_Equal;
        case CLOVER_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case CLOVER_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case CLOVER_KEY_WORLD_1: return ImGuiKey_Oem102;
        case CLOVER_KEY_WORLD_2: return ImGuiKey_Oem102;
        case CLOVER_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case CLOVER_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case CLOVER_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case CLOVER_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case CLOVER_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case CLOVER_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case CLOVER_KEY_PAUSE: return ImGuiKey_Pause;
        case CLOVER_KEY_KP_0: return ImGuiKey_Keypad0;
        case CLOVER_KEY_KP_1: return ImGuiKey_Keypad1;
        case CLOVER_KEY_KP_2: return ImGuiKey_Keypad2;
        case CLOVER_KEY_KP_3: return ImGuiKey_Keypad3;
        case CLOVER_KEY_KP_4: return ImGuiKey_Keypad4;
        case CLOVER_KEY_KP_5: return ImGuiKey_Keypad5;
        case CLOVER_KEY_KP_6: return ImGuiKey_Keypad6;
        case CLOVER_KEY_KP_7: return ImGuiKey_Keypad7;
        case CLOVER_KEY_KP_8: return ImGuiKey_Keypad8;
        case CLOVER_KEY_KP_9: return ImGuiKey_Keypad9;
        case CLOVER_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case CLOVER_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case CLOVER_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case CLOVER_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case CLOVER_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case CLOVER_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case CLOVER_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case CLOVER_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case CLOVER_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case CLOVER_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case CLOVER_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case CLOVER_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case CLOVER_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case CLOVER_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case CLOVER_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case CLOVER_KEY_MENU: return ImGuiKey_Menu;
        case CLOVER_KEY_0: return ImGuiKey_0;
        case CLOVER_KEY_1: return ImGuiKey_1;
        case CLOVER_KEY_2: return ImGuiKey_2;
        case CLOVER_KEY_3: return ImGuiKey_3;
        case CLOVER_KEY_4: return ImGuiKey_4;
        case CLOVER_KEY_5: return ImGuiKey_5;
        case CLOVER_KEY_6: return ImGuiKey_6;
        case CLOVER_KEY_7: return ImGuiKey_7;
        case CLOVER_KEY_8: return ImGuiKey_8;
        case CLOVER_KEY_9: return ImGuiKey_9;
        case CLOVER_KEY_A: return ImGuiKey_A;
        case CLOVER_KEY_B: return ImGuiKey_B;
        case CLOVER_KEY_C: return ImGuiKey_C;
        case CLOVER_KEY_D: return ImGuiKey_D;
        case CLOVER_KEY_E: return ImGuiKey_E;
        case CLOVER_KEY_F: return ImGuiKey_F;
        case CLOVER_KEY_G: return ImGuiKey_G;
        case CLOVER_KEY_H: return ImGuiKey_H;
        case CLOVER_KEY_I: return ImGuiKey_I;
        case CLOVER_KEY_J: return ImGuiKey_J;
        case CLOVER_KEY_K: return ImGuiKey_K;
        case CLOVER_KEY_L: return ImGuiKey_L;
        case CLOVER_KEY_M: return ImGuiKey_M;
        case CLOVER_KEY_N: return ImGuiKey_N;
        case CLOVER_KEY_O: return ImGuiKey_O;
        case CLOVER_KEY_P: return ImGuiKey_P;
        case CLOVER_KEY_Q: return ImGuiKey_Q;
        case CLOVER_KEY_R: return ImGuiKey_R;
        case CLOVER_KEY_S: return ImGuiKey_S;
        case CLOVER_KEY_T: return ImGuiKey_T;
        case CLOVER_KEY_U: return ImGuiKey_U;
        case CLOVER_KEY_V: return ImGuiKey_V;
        case CLOVER_KEY_W: return ImGuiKey_W;
        case CLOVER_KEY_X: return ImGuiKey_X;
        case CLOVER_KEY_Y: return ImGuiKey_Y;
        case CLOVER_KEY_Z: return ImGuiKey_Z;
        case CLOVER_KEY_F1: return ImGuiKey_F1;
        case CLOVER_KEY_F2: return ImGuiKey_F2;
        case CLOVER_KEY_F3: return ImGuiKey_F3;
        case CLOVER_KEY_F4: return ImGuiKey_F4;
        case CLOVER_KEY_F5: return ImGuiKey_F5;
        case CLOVER_KEY_F6: return ImGuiKey_F6;
        case CLOVER_KEY_F7: return ImGuiKey_F7;
        case CLOVER_KEY_F8: return ImGuiKey_F8;
        case CLOVER_KEY_F9: return ImGuiKey_F9;
        case CLOVER_KEY_F10: return ImGuiKey_F10;
        case CLOVER_KEY_F11: return ImGuiKey_F11;
        case CLOVER_KEY_F12: return ImGuiKey_F12;
        case CLOVER_KEY_F13: return ImGuiKey_F13;
        case CLOVER_KEY_F14: return ImGuiKey_F14;
        case CLOVER_KEY_F15: return ImGuiKey_F15;
        case CLOVER_KEY_F16: return ImGuiKey_F16;
        case CLOVER_KEY_F17: return ImGuiKey_F17;
        case CLOVER_KEY_F18: return ImGuiKey_F18;
        case CLOVER_KEY_F19: return ImGuiKey_F19;
        case CLOVER_KEY_F20: return ImGuiKey_F20;
        case CLOVER_KEY_F21: return ImGuiKey_F21;
        case CLOVER_KEY_F22: return ImGuiKey_F22;
        case CLOVER_KEY_F23: return ImGuiKey_F23;
        case CLOVER_KEY_F24: return ImGuiKey_F24;
        default: return ImGuiKey_None;
        }
	}

	ImGuiLayer::ImGuiLayer()
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
        CV_PROFILE_FUNCTION();

        IMGUI_CHECKVERSION();
		ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
        CV_PROFILE_FUNCTION();

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
	}

    void ImGuiLayer::OnImGuiRender()
    {
    }

    void ImGuiLayer::Begin()
    {
        CV_PROFILE_FUNCTION();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        CV_PROFILE_FUNCTION();

        ImGuiIO& io = ImGui::GetIO();

        Application& app = Application::Get();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();

            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

}