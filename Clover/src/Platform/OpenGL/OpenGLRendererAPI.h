#pragma once

#include "Clover/Renderer/RendererAPI.h"

namespace Clover
{
	class OpenGLRendererAPI : public RendererAPI
	{
		virtual void SetClearColor(const Color& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}