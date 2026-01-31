#include "cvpch.h"
#include "Texture.h"

#include "Clover/Renderer/Renderer.h"

#include "Backends/OpenGL/OpenGLTexture.h"

namespace Clover
{
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return CreateRef<OpenGLTexture2D>(width, height);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
			case RendererAPI::API::OpenGL:    return CreateRef<OpenGLTexture2D>(path);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}