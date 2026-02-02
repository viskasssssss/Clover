#pragma once

#include "Clover.h"
#include "Panels/SceneHierarchyPanel.h"

namespace Clover
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController m_CameraController;

		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader > m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;

		bool m_PrimaryCamera = true;

		Ref<Texture2D> m_CatTexture;

		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;
		vec2 m_ViewportSize = { 0.0f, 0.0f };

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
	};
}