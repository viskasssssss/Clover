#include "cvpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Clover
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return std::make_shared<OpenGLVertexArray>();
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}