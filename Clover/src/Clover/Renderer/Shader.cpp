#include "cvpch.h"
#include "Shader.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Clover
{
	Shader* Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return new OpenGLShader(filepath);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}

	Shader* Shader::Create(const std::string& vertSrc, const std::string& fragSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      CLOVER_CORE_ASSERT(false, "RendererAPI::None isn't valid"); return nullptr;
		case RendererAPI::API::OpenGL:    return new OpenGLShader(vertSrc, fragSrc);
		}
		CLOVER_CORE_ASSERT(false, "Unsupported RendererAPI");
		return nullptr;
	}
}