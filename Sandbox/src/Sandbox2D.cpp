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

	{
		CV_PROFILE_SCOPE("Renderer Prep");
		Clover::RenderCommand::SetClearColor({ 0.05f, 0.05f, 0.10f, 1.0f });
		Clover::RenderCommand::Clear();
	}

	{
		CV_PROFILE_SCOPE("Renderer Draw");
		Clover::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Clover::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });

		//for (int x = -15; x < 16; x++)
		//{
		//	for (int y = -15; y < 16; y++)
		//		Clover::Renderer2D::DrawQuad({ x * 0.4f, y * 0.4f, -0.1f }, { 0.4f, 0.4f }, m_CatTexture);
		//}

		Clover::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 6.0f, 6.0f }, m_CatTexture, 32.0f, { 0.8f, 0.2f, 0.3f, 1.0f });

		Clover::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	CV_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Clover::Event& e)
{
	m_CameraController.OnEvent(e);
}
