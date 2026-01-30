#pragma once

#include "Clover/Math.h"

#include "VertexArray.h"

namespace Clover
{
	class RendererAPI
	{
	public:
		// TODO: Direct3D, Vulkan
		enum class API
		{
			None = 0, OpenGL = 1
		};
		
		virtual void SetClearColor(const Color& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};
}