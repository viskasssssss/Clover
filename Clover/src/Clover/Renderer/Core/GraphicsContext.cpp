#include "cvpch.h"
#include "GraphicsContext.h"

#include "Clover/Renderer/Renderer.h"

#include "Backends/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace Clover
{
	Ref<GraphicsContext> GraphicsContext::Create(GLFWwindow* windowHandle)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return CreateRef<OpenGLContext>(windowHandle);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}