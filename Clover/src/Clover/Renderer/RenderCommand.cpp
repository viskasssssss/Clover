#include "cvpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Clover
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}