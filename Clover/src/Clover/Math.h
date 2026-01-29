#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp> 
#include <glm/gtc/type_ptr.hpp>

namespace Clover
{
	// TODO: Math Class
	using Vector4 = glm::vec4;
	using Vector3 = glm::vec3;
	using Vector2 = glm::vec2;

	using Color = Vector4;
	using RGBColor = Vector3;
	using RGBAColor = Color;

	using Matrix4x4 = glm::mat4x4;
	using Matrix4 = glm::mat4;

	using Matrix3x3 = glm::mat3x3;
	using Matrix3 = glm::mat3;

	using Matrix2x2 = glm::mat2x2;
	using Matrix2 = glm::mat2;

	using vec4 = Vector4;
	using vec3 = Vector3;
	using vec2 = Vector2;

	using color = Color;

	using mat4 = Matrix4;
	using mat3 = Matrix3;
	using mat2 = Matrix2;
}