#include "EditorLayer.h"

#include "EditorThemes.h"

#include <imgui/imgui.h>

namespace Clover
{
	EditorLayer::EditorLayer()
		: Layer("EditorLayer"), m_CameraController(1280.0f / 720.0f)
	{
	}

	void EditorLayer::OnAttach()
	{
		CV_PROFILE_FUNCTION();

		m_CatTexture = Clover::Texture2D::Create("assets/textures/cat.png");

		Clover::FramebufferSpecification fbSpec;
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		m_Framebuffer = Clover::Framebuffer::Create(fbSpec);

		Themes::ApplyCloverDarkTheme();
	}

	void EditorLayer::OnDetach()
	{
		CV_PROFILE_FUNCTION();
	}

	void EditorLayer::OnUpdate(Clover::Timestep ts)
	{
		CV_PROFILE_FUNCTION();

		if (m_ViewportFocused)
			m_CameraController.OnUpdate(ts);

		Clover::Renderer2D::ResetStats();
		{
			CV_PROFILE_SCOPE("Renderer Prep");

			m_Framebuffer->Bind();

			Clover::RenderCommand::SetClearColor({ 0.05f, 0.05f, 0.10f, 1.0f });
			Clover::RenderCommand::Clear();
		}

		{
			static float rotation = 0.0f;
			rotation += ts * 50.0f;

			CV_PROFILE_SCOPE("Renderer Draw");
			Clover::Renderer2D::BeginScene(m_CameraController.GetCamera());

			Clover::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CatTexture);
			Clover::Renderer2D::DrawRotatedQuad({ 0.5f, 1.0f }, { 1.0f, 1.0f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });

			Clover::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
			Clover::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });

			for (float y = -10.0f; y < 10.0f; y += 0.5f)
			{
				for (float x = -10.0f; x < 10.0f; x += 0.5f)
				{
					Clover::Color color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.5f };
					Clover::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
				}
			}

			Clover::Renderer2D::EndScene();

			m_Framebuffer->Unbind();
		}
	}

	void EditorLayer::OnImGuiRender()
	{
		CV_PROFILE_FUNCTION();

		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("Dockspace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// Dockspace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("Dockspace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit", "Alt+F4")) Clover::Application::Get().Close();
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}


		ImGui::Begin("Statistics");

		auto stats = Clover::Renderer2D::GetStats();
		ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });

		ImGui::Begin("Scene View");

		m_ViewportFocused = ImGui::IsWindowFocused();
		m_ViewportHovered = ImGui::IsWindowHovered();
		Application::Get().GetImGuiLayer()->BlockEvents(!m_ViewportFocused && !m_ViewportHovered);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		if (m_ViewportSize != *((vec2*)&viewportPanelSize) && viewportPanelSize.x > 0 && viewportPanelSize.y > 0)
		{
			m_Framebuffer->Resize((uint32_t)viewportPanelSize.x, (uint32_t)viewportPanelSize.y);
			m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

			m_CameraController.OnResize(viewportPanelSize.x, viewportPanelSize.y);

			ImDrawList* drawList = ImGui::GetWindowDrawList();
			ImVec2 min = ImGui::GetCursorScreenPos();
			ImVec2 max = ImVec2(min.x + viewportPanelSize.x, min.y + viewportPanelSize.y);
			drawList->AddRectFilled(min, max, IM_COL32(0, 0, 0, 255));
			ImGui::Dummy(viewportPanelSize);
		}
		else
		{
			uint32_t textureID = m_Framebuffer->GetColorAttachmentRendererID();
			ImGui::Image(textureID, ImVec2{ m_ViewportSize.x, m_ViewportSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		}

		

		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::End();
	}

	void EditorLayer::OnEvent(Clover::Event& e)
	{
		m_CameraController.OnEvent(e);
	}

}