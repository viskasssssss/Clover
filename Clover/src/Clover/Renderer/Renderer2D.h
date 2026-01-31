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

		static void DrawQuad(const vec2& position, const vec2& size, const Ref<Texture2D>& texture);
		static void DrawQuad(const vec3& position, const vec2& size, const Ref<Texture2D>& texture);
	};
}