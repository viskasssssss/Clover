#pragma once

#include "OrthographicCamera.h"

#include "Clover/Core/Math.h"

#include "Texture.h"

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

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Primitives
		static void DrawQuad(const vec2& position, const vec2& size, const color& color);
		static void DrawQuad(const vec3& position, const vec2& size, const color& color);

		static void DrawQuad(const vec2& position, const vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
		static void DrawQuad(const vec3& position, const vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));

		static void DrawRotatedQuad(const vec2& position, const vec2& size, float rotation, const color& color);
		static void DrawRotatedQuad(const vec3& position, const vec2& size, float rotation, const color& color);
																		  
		static void DrawRotatedQuad(const vec2& position, const vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
		static void DrawRotatedQuad(const vec3& position, const vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const color& tintColor = color(1.0f));
	};
}