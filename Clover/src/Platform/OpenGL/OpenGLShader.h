#pragma once

#include "Clover/Renderer/Shader.h"
#include "Clover/Math.h"

namespace Clover
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertSrc, const std::string& fragSrc);
		~OpenGLShader();

		void Bind() const override;
		void Unbind() const override;

		void UploadUniformInt(const std::string& name, int value);
		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const vec2& vector);
		void UploadUniformFloat3(const std::string& name, const vec3& vector);
		void UploadUniformFloat4(const std::string& name, const vec4& vector);
		void UploadUniformMat4(const std::string& name, const mat4& matrix);
		void UploadUniformMat3(const std::string& name, const mat4& matrix);
	private:
		uint32_t m_RendererID;
	};
}