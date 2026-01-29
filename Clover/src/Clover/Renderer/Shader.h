#pragma once

#include <string>
#include "Clover/Math.h"

namespace Clover
{
	class Shader
	{
	public:
		Shader(const std::string& vertSrc, const std::string& fragSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniformMat4(const std::string& name, const mat4& matrix);
	private:
		uint32_t m_RendererID;
	};
}