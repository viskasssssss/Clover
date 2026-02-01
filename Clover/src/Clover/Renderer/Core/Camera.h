#pragma once

#include "Clover/Core/Base/Math.h"

namespace Clover
{
	class Camera
	{
	public:
		Camera(const mat4& projection)
			: m_Projection(projection) {}

		const mat4& GetProjection() const { return m_Projection; }
	private:
		mat4 m_Projection;
	};
}