#pragma once

#include "Clover/Core/Layer.h"

#include "Clover/Events/ApplicationEvent.h"
#include "Clover/Events/MouseEvent.h"
#include "Clover/Events/KeyEvent.h"

namespace Clover
{
	class CLOVER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}