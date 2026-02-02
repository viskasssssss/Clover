#pragma once

#include "Clover/Core/Base/Math.h"

namespace Clover
{
	class Camera
	{
	public:
		Camera() = default;
		Camera(const mat4& projection)
			: m_Projection(projection) {}

		virtual ~Camera() = default;

		const mat4& GetProjection() const { return m_Projection; }
	protected:
		mat4 m_Projection = mat4(1.0f);
	};
}