#pragma once

namespace Clover
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		// TODO: virtual void UploadUBO(UniformBuffer buffer);

		static Shader* Create(const std::string& filepath);
		static Shader* Create(const std::string& vertSrc, const std::string& fragSrc);
	};
}