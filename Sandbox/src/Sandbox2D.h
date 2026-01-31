#pragma once

#include "Clover.h"

class Sandbox2D : public Clover::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(Clover::Timestep ts) override;
	void OnImGuiRender() override;
	void OnEvent(Clover::Event& e) override;
private:
	Clover::OrthographicCameraController m_CameraController;

	// Temp
	Clover::Ref<Clover::VertexArray> m_SquareVA;
	Clover::Ref<Clover::Shader > m_FlatColorShader;

	Clover::Ref<Clover::Texture2D> m_CatTexture;

	Clover::Color m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};