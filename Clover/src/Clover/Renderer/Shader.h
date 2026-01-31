#pragma once

#include <string>
#include <unordered_map>

#include "Clover/Core/Math.h"

namespace Clover
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetMat4(const std::string& name, const mat4& value) = 0;
		virtual void SetMat3(const std::string& name, const mat3& value) = 0;
		virtual void SetFloat4(const std::string& name, const vec4& value) = 0;
		virtual void SetFloat3(const std::string& name, const vec3& value) = 0;
		virtual void SetFloat2(const std::string& name, const vec2& value) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetInt(const std::string& name, int value) = 0;

		// TODO: virtual void SetUBO(UniformBuffer buffer);

		virtual const std::string GetName() const = 0;

		static Ref<Shader> Create(const std::string& filepath);
		static Ref<Shader> Create(const std::string& name, const std::string& vertSrc, const std::string& fragSrc);
	};

	class ShaderLibrary
	{
	public:
		void Add(const Ref<Shader>& shader);
		void Add(const std::string& name, const Ref<Shader>& shader);
		Ref<Shader> Load(const std::string& filepath);
		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}