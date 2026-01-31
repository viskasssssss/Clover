#pragma once

#include "Clover/Renderer/Core/GraphicsContext.h"

struct GLFWwindow;

namespace Clover
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}