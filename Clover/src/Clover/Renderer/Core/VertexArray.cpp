#include "cvpch.h"
#include "VertexArray.h"

#include "Clover/Renderer/Renderer.h"

#include "Backends/OpenGL/OpenGLVertexArray.h"

namespace Clover
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return CreateRef<OpenGLVertexArray>();
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}