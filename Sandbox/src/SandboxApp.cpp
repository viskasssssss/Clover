#include <Clover.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include <imgui/imgui.h>


class ExampleLayer : public Clover::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Clover::VertexArray::Create());

		float vertices[24] = {
			-0.5f, -0.5f, 0.0f,		0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f,		0.2f, 0.3f, 0.7f, 1.0f,
			 0.0f,  0.5f, 0.0f,		0.8f, 0.8f, 0.2f, 1.0f,
		};

		Clover::Ref<Clover::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Clover::VertexBuffer::Create(vertices, sizeof(vertices)));

		Clover::BufferLayout layout = {
			{ Clover::ShaderDataType::Float3, "a_Position"},
			{ Clover::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);


		unsigned int indices[3] = { 0, 1, 2 };
		Clover::Ref<Clover::IndexBuffer> indexBuffer;
		indexBuffer.reset(Clover::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Clover::VertexArray::Create());

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

		std::string vertexSrc = R"(
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_Position;
out vec4 v_Color;

void main()
{
	v_Position = a_Position;
	v_Color = a_Color;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
)";

		std::string fragmentSrc = R"(
#version 330 core

layout(location = 0) out vec4 color;
 
in vec3 v_Position;
in vec4 v_Color;

void main()
{
	color = vec4(v_Position * 0.5 + 0.5, 1.0);
	color = v_Color;
}
)";

		m_Shader.reset(Clover::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorVertexSrc = R"(
#version 330 core

layout(location = 0) in vec3 a_Position;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_Position;

void main()
{
	v_Position = a_Position;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
)";

		std::string flatColorFragmentSrc = R"(
#version 330 core

layout(location = 0) out vec4 color;

uniform vec3 u_Color;
 
in vec3 v_Position;

void main()
{
	color = vec4(u_Color, 1.0);
}
)";

		m_FlatColorShader.reset(Clover::Shader::Create(flatColorVertexSrc, flatColorFragmentSrc));

		std::string textureVertexSrc = R"(
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec2 v_TexCoord;

void main()
{
	v_TexCoord = a_TexCoord;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
)";

		std::string textureFragmentSrc = R"(
#version 330 core

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;
 
in vec2 v_TexCoord;

void main()
{
	color = texture(u_Texture, v_TexCoord);
}
)";

		m_TextureShader.reset(Clover::Shader::Create(textureVertexSrc, textureFragmentSrc));

		m_Texture = Clover::Texture2D::Create("assets/textures/cat.png");
		m_CloverLogoTexture = Clover::Texture2D::Create("assets/textures/Clover-Logo.png"); 

		std::dynamic_pointer_cast<Clover::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Clover::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Clover::Timestep ts) override
	{
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Left))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Right))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Down))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::Up))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (Clover::Input::IsKeyPressed(Clover::KeyCode::A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Clover::Input::IsKeyPressed(Clover::KeyCode::D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Clover::RenderCommand::SetClearColor({ 0.05f, 0.05f, 0.10f, 1.0f });
		Clover::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Clover::Renderer::BeginScene(m_Camera);

		Clover::mat4 scale = glm::scale(Clover::mat4(1.0f), Clover::vec3(0.1f));

		std::dynamic_pointer_cast<Clover::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Clover::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				Clover::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				Clover::mat4 transform = glm::translate(Clover::mat4(1.0f), pos) * scale;

				Clover::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		Clover::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(Clover::mat4(1.0f), Clover::vec3(1.5f)));

		m_CloverLogoTexture->Bind();
		Clover::Renderer::Submit(m_TextureShader, m_SquareVA, 
			glm::translate(Clover::mat4(1.0f), Clover::vec3(1.5f, 0.0f, 0.0f)) *  glm::scale(Clover::mat4(1.0f), Clover::vec3(1.5f))
		);


		// Triangle
		//Clover::Renderer::Submit(m_Shader, m_VertexArray);

		Clover::Renderer::EndScene();
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Settings");

		ImGui::ColorEdit3("Square color", glm::value_ptr(m_SquareColor));

		ImGui::End();
	}

	void OnEvent(Clover::Event& event) override
	{
		
	}
private:
	Clover::Ref<Clover::Shader > m_Shader;
	Clover::Ref<Clover::VertexArray> m_VertexArray;

	Clover::Ref<Clover::Shader> m_FlatColorShader, m_TextureShader;
	Clover::Ref<Clover::VertexArray> m_SquareVA;

	Clover::Ref<Clover::Texture2D> m_Texture, m_CloverLogoTexture;

	Clover::OrthographicCamera m_Camera;
	Clover::vec3 m_CameraPosition;
	float m_CameraRotation = 0.0f;

	float m_CameraMoveSpeed = 5.0f;
	float m_CameraRotationSpeed = 180.0f;

	Clover::RGBColor m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Clover::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Clover::Application* Clover::CreateApplication()
{
	return new Sandbox();
}