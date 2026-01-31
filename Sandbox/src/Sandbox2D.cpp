#include "Sandbox2D.h"

#include <imgui/imgui.h>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	CV_PROFILE_FUNCTION();

	m_CatTexture = Clover::Texture2D::Create("assets/textures/cat.png");
}

void Sandbox2D::OnDetach()
{
	CV_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Clover::Timestep ts)
{
	CV_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	Clover::Renderer2D::ResetStats();
	{
		CV_PROFILE_SCOPE("Renderer Prep");
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
	}
}

void Sandbox2D::OnImGuiRender()
{
	CV_PROFILE_FUNCTION();

	ImGui::Begin("Statistics");

	auto stats = Clover::Renderer2D::GetStats();
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::End();

	ImGui::Begin("Settings");

	ImGui::ColorEdit4("Square color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Clover::Event& e)
{
	m_CameraController.OnEvent(e);
}
