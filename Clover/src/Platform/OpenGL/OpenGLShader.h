#pragma once

#include "Clover/Renderer/Shader.h"
#include "Clover/Core/Math.h"

// TODO: Remove
typedef unsigned int GLenum;

namespace Clover
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertSrc, const std::string& fragSrc);
		~OpenGLShader();

		void Bind() const override;
		void Unbind() const override;

		virtual void SetMat4(const std::string& name, const mat4& value) override;
		virtual void SetMat3(const std::string& name, const mat3& value) override;
		virtual void SetFloat4(const std::string& name, const vec4& value) override;
		virtual void SetFloat3(const std::string& name, const vec3& value) override;
		virtual void SetFloat2(const std::string& name, const vec2& value) override;
		virtual void SetFloat(const std::string& name, float value) override;
		virtual void SetInt(const std::string& name, int value) override;

		const std::string GetName() const override { return m_Name; }

		void UploadUniformInt(const std::string& name, int value);
		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const vec2& vector);
		void UploadUniformFloat3(const std::string& name, const vec3& vector);
		void UploadUniformFloat4(const std::string& name, const vec4& vector);
		void UploadUniformMat4(const std::string& name, const mat4& matrix);
		void UploadUniformMat3(const std::string& name, const mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);

		uint32_t m_RendererID;
		std::string m_Name;
	};
}