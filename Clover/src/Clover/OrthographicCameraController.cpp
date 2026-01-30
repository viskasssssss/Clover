#include "cvpch.h"
#include "OrthographicCameraController.h"

#include "Clover/Input.h"
#include "Clover/Keycodes.h"

namespace Clover
{
	OrthographicCameraController::OrthographicCameraController(float aspectratio, bool rotation)
		: m_AspectRatio(aspectratio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{

	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		if (Input::IsKeyPressed(KeyCode::A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(KeyCode::D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(KeyCode::S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(KeyCode::W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;

		if (m_Rotation)
		{
			if (Input::IsKeyPressed(KeyCode::Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(KeyCode::E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(CLOVER_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(CLOVER_BIND_EVENT_FN(OrthographicCameraController::OnWindowResize));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.3f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}