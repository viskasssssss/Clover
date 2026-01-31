#include "cvpch.h"
#include "RenderCommand.h"

#include "Backends/OpenGL/OpenGLRendererAPI.h"

namespace Clover
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}