#pragma once

#include "Clover/Renderer/Core/OrthographicCamera.h"

#include "Clover/Core/Base/Math.h"

#include "Clover/Renderer/Core/Texture.h"
#include "Clover/Renderer/Core/Camera.h"

namespace Clover
{
	/**
	* @brief Basic Renderer2D Class
	* 
	* Used for rendering basic 2D geometry
	*/
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const mat4& transform);
		static void BeginScene(const OrthographicCamera& camera); // TODO: REMOVE
		static void EndScene();
		static void Flush();

		// Primitives
		static void DrawQuad(const vec2& position, const vec2& size, const color& color);
		static void DrawQuad(const vec3& position, const vec2& size, const color& color);

		static void DrawQuad(const vec2& position, const vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
		static void DrawQuad(const vec3& position, const vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));

		static void DrawQuad(const mat4& transform, const color& color);
		static void DrawQuad(const mat4& transform, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
		
		static void DrawRotatedQuad(const vec2& position, const vec2& size, float rotation, const color& color);
		static void DrawRotatedQuad(const vec3& position, const vec2& size, float rotation, const color& color);
																		  
		static void DrawRotatedQuad(const vec2& position, const vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
		static void DrawRotatedQuad(const vec3& position, const vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
	
		// Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }
		};

		static Statistics GetStats();
		static void ResetStats();
	private:
		static void FlushAndReset();
	};
}