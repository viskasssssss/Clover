#pragma once

#include "Clover/Core/Layers/Layer.h"

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
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool value) { m_BlockEvents = value; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}