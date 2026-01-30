#include "Sandbox2D.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include <imgui/imgui.h>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_SquareVA = Clover::VertexArray::Create();

	float squareVertices[20] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	Clover::Ref<Clover::VertexBuffer> squareVB;
	squareVB.reset(Clover::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

	squareVB->SetLayout({
		{ Clover::ShaderDataType::Float3, "a_Position"},
		{ Clover::ShaderDataType::Float2, "a_TexCoord"}
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Clover::Ref<Clover::IndexBuffer> squareIB;
	squareIB.reset(Clover::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Clover::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Clover::Timestep ts)
{
	m_CameraController.OnUpdate(ts);

	Clover::RenderCommand::SetClearColor({ 0.05f, 0.05f, 0.10f, 1.0f });
	Clover::RenderCommand::Clear();

	Clover::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Clover::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Clover::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Clover::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(Clover::mat4(1.0f), Clover::vec3(1.5f)));

	Clover::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Clover::Event& e)
{
	m_CameraController.OnEvent(e);
}
