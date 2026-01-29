#include <Clover.h>

#include <imgui/imgui.h>

class ExampleLayer : public Clover::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_SquarePosition(0.0f)
	{
		m_VertexArray.reset(Clover::VertexArray::Create());

		float vertices[24] = {
			-0.5f, -0.5f, 0.0f,		0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f,		0.2f, 0.3f, 0.7f, 1.0f,
			 0.0f,  0.5f, 0.0f,		0.8f, 0.8f, 0.2f, 1.0f,
		};

		std::shared_ptr<Clover::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Clover::VertexBuffer::Create(vertices, sizeof(vertices)));

		Clover::BufferLayout layout = {
			{ Clover::ShaderDataType::Float3, "a_Position"},
			{ Clover::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);


		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<Clover::IndexBuffer> indexBuffer;
		indexBuffer.reset(Clover::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Clover::VertexArray::Create());

		float squareVertices[12] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		std::shared_ptr<Clover::VertexBuffer> squareVB;
		squareVB.reset(Clover::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ Clover::ShaderDataType::Float3, "a_Position"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Clover::IndexBuffer> squareIB;
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

		m_Shader.reset(new Clover::Shader(vertexSrc, fragmentSrc));

		std::string blueVertexSrc = R"(
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

		std::string blueFragmentSrc = R"(
#version 330 core

layout(location = 0) out vec4 color;
 
in vec3 v_Position;

void main()
{
	color = vec4(0.2, 0.3, 0.8, 1.0);
}
)";

		m_BlueShader.reset(new Clover::Shader(blueVertexSrc, blueFragmentSrc));
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

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				Clover::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				Clover::mat4 transform = glm::translate(Clover::mat4(1.0f), pos) * scale;
				Clover::Renderer::Submit(m_BlueShader, m_SquareVA, transform);
			}
		}

		Clover::Renderer::Submit(m_Shader, m_VertexArray);

		Clover::Renderer::EndScene();
	}

	void OnImGuiRender() override
	{
		
	}

	void OnEvent(Clover::Event& event) override
	{
		
	}
private:
	std::shared_ptr<Clover::Shader > m_Shader;
	std::shared_ptr<Clover::VertexArray> m_VertexArray;

	std::shared_ptr<Clover::Shader> m_BlueShader;
	std::shared_ptr<Clover::VertexArray> m_SquareVA;

	Clover::OrthographicCamera m_Camera;
	Clover::vec3 m_CameraPosition;
	float m_CameraRotation = 0.0f;

	float m_CameraMoveSpeed = 5.0f;
	float m_CameraRotationSpeed = 180.0f;
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