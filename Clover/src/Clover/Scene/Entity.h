#pragma once

#include "Scene.h"

#include <entt.hpp>

namespace Clover
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename ... Args>
		T& AddComponent(Args&&... args)
		{
			CLOVER_CORE_ASSERT(!HasComponent<T>(), "Given Entity alredy have component of this type");
			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			CLOVER_CORE_ASSERT(HasComponent<T>(), "Given Entity doesn't have component of this type");
			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.all_of<T>(m_EntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			CLOVER_CORE_ASSERT(HasComponent<T>(), "Given Entity doesn't have component of this type");
			m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		operator bool() const { return m_EntityHandle != entt::null; }
	private:
		entt::entity m_EntityHandle = entt::null;
		Scene* m_Scene = nullptr;
	};
}