#pragma once

#include "Clover/Core/Base/Math.h"

namespace Clover
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		const vec3& GetPosition() const { return m_Position; }
		void SetPosition(const vec3& position) { m_Position = position; RecalculateViewMatrix(); }

		float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		void SetProjection(float left, float right, float bottom, float top);

		const mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();

		mat4 m_ProjectionMatrix;
		mat4 m_ViewMatrix;
		mat4 m_ViewProjectionMatrix;

		vec3 m_Position = { 0.0f, 0.0f, -5.0f };
		float m_Rotation = 0.0f;
	};
}