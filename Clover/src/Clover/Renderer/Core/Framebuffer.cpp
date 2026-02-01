#include "cvpch.h"
#include "Framebuffer.h"

#include "Clover/Renderer/Renderer.h"

#include "Backends/OpenGL/OpenGLFramebuffer.h"

namespace Clover
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return CreateRef<OpenGLFramebuffer>(spec);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}