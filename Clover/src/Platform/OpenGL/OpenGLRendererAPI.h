#pragma once

#include "Clover/Renderer/RendererAPI.h"

namespace Clover
{
	class OpenGLRendererAPI : public RendererAPI
	{
		virtual void Init() override;

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void SetClearColor(const Color& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}