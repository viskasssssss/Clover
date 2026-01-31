#pragma once

#include "Clover/Renderer/Core/RenderCommand.h"

#include "Clover/Renderer/Core/OrthographicCamera.h"
#include "Clover/Renderer/Core/Shader.h"

namespace Clover
{
	/**
	* @brief Main Renderer Class
	*/
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();
		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const mat4& transform = mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}