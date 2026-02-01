#pragma once

#include "Clover/Core/Base/Math.h"

#include "Clover/Renderer/Core/Camera.h"

namespace Clover
{
	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TransformComponent
	{
		mat4 Transform{ 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const mat4& transform)
			: Transform(transform) {}

		operator mat4& () { return Transform; }
		operator const mat4& const () { return Transform; }
	};

	struct SpriteRendererComponent
	{
		color Color{ 1.0f, 1.0f, 1.0f, 1.0f };

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const color& color)
			: Color(color) {}
	};

	struct CameraComponent
	{
		Clover::Camera Camera;
		bool Main = true;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const mat4& projection)
			: Camera(projection) {}
	};
}