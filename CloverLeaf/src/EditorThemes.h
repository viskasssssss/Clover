#pragma once

#include <imgui/imgui.h>

namespace Clover
{
    namespace Themes
    {
        void ApplyCloverDarkTheme()
        {
            auto& style = ImGui::GetStyle();
            auto& colors = style.Colors;

            // === Style ===
            style.WindowPadding = ImVec2(8.0f, 6.0f);
            style.WindowRounding = 6.0f;
            style.FramePadding = ImVec2(6.0f, 4.0f);
            style.FrameRounding = 4.0f;
            style.ItemSpacing = ImVec2(8.0f, 5.0f);
            style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
            style.CellPadding = ImVec2(6.0f, 4.0f);
            style.IndentSpacing = 21.0f;
            style.ScrollbarSize = 13.0f;
            style.ScrollbarRounding = 6.0f;
            style.GrabMinSize = 10.0f;
            style.GrabRounding = 3.0f;
            style.TabRounding = 4.0f;
            style.TabBorderSize = 1.0f;
            style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
            style.WindowMenuButtonPosition = ImGuiDir_Right;
            style.ChildRounding = 4.0f;
            style.PopupRounding = 4.0f;
            style.FrameBorderSize = 0.0f;
            style.WindowBorderSize = 1.0f;

            style.AntiAliasedLinesUseTex = true;
            style.AntiAliasedFill = true;

            // === Color Palette (Monochrome Dark) ===
            ImVec4 black = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
            ImVec4 very_dark_gray = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
            ImVec4 dark_gray = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
            ImVec4 medium_gray = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
            ImVec4 light_gray = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
            ImVec4 white = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
            ImVec4 highlight = ImVec4(0.28f, 0.28f, 0.28f, 1.00f); // Subtle highlight
            ImVec4 hover = ImVec4(0.35f, 0.35f, 0.35f, 0.80f);
            ImVec4 active = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);

            // === Apply Colors ===
            colors[ImGuiCol_Text] = white;
            colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
            colors[ImGuiCol_WindowBg] = black;
            colors[ImGuiCol_ChildBg] = dark_gray;
            colors[ImGuiCol_PopupBg] = dark_gray;
            colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 0.30f);
            colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            colors[ImGuiCol_FrameBg] = dark_gray;
            colors[ImGuiCol_FrameBgHovered] = medium_gray;
            colors[ImGuiCol_FrameBgActive] = medium_gray;
            colors[ImGuiCol_TitleBg] = very_dark_gray;
            colors[ImGuiCol_TitleBgActive] = dark_gray;
            colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
            colors[ImGuiCol_MenuBarBg] = dark_gray;
            colors[ImGuiCol_ScrollbarBg] = very_dark_gray;
            colors[ImGuiCol_ScrollbarGrab] = medium_gray;
            colors[ImGuiCol_ScrollbarGrabHovered] = hover;
            colors[ImGuiCol_ScrollbarGrabActive] = active;
            colors[ImGuiCol_CheckMark] = highlight;
            colors[ImGuiCol_SliderGrab] = highlight;
            colors[ImGuiCol_SliderGrabActive] = active;
            colors[ImGuiCol_Button] = medium_gray;
            colors[ImGuiCol_ButtonHovered] = hover;
            colors[ImGuiCol_ButtonActive] = active;
            colors[ImGuiCol_Header] = medium_gray;
            colors[ImGuiCol_HeaderHovered] = hover;
            colors[ImGuiCol_HeaderActive] = active;
            colors[ImGuiCol_Separator] = light_gray;
            colors[ImGuiCol_SeparatorHovered] = hover;
            colors[ImGuiCol_SeparatorActive] = active;
            colors[ImGuiCol_ResizeGrip] = medium_gray;
            colors[ImGuiCol_ResizeGripHovered] = hover;
            colors[ImGuiCol_ResizeGripActive] = active;
            colors[ImGuiCol_Tab] = dark_gray;
            colors[ImGuiCol_TabHovered] = hover;
            colors[ImGuiCol_TabActive] = medium_gray;
            colors[ImGuiCol_TabUnfocused] = very_dark_gray;
            colors[ImGuiCol_TabUnfocusedActive] = dark_gray;
            colors[ImGuiCol_DockingPreview] = ImVec4(0.28f, 0.28f, 0.28f, 0.70f);
            colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
            colors[ImGuiCol_TableHeaderBg] = dark_gray;
            colors[ImGuiCol_TableBorderStrong] = light_gray;
            colors[ImGuiCol_TableBorderLight] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
            colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.15f, 0.15f, 0.15f, 0.06f);
            colors[ImGuiCol_PlotLines] = white;
            colors[ImGuiCol_PlotLinesHovered] = hover;
            colors[ImGuiCol_PlotHistogram] = highlight;
            colors[ImGuiCol_PlotHistogramHovered] = hover;
            colors[ImGuiCol_TextSelectedBg] = ImVec4(0.30f, 0.30f, 0.30f, 0.50f);
            colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.70f);
        }
    }
}