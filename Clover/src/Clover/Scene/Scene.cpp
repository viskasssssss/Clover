#include "cvpch.h"
#include "Scene.h"

#include "Components.h"
#include "Clover/Renderer/2D/Renderer2D.h"

#include "Clover/Scene/Entity.h"

namespace Clover
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}

	void Scene::OnUpdate(Timestep ts)
	{
		// 2D Render
		Camera* mainCamera = nullptr;
		mat4* mainCameraTransform = nullptr;
		{
			auto view = m_Registry.view<TransformComponent, CameraComponent>();
			for (auto entity : view)
			{
				auto& transform = view.get<TransformComponent>(entity);
				auto& camera = view.get<CameraComponent>(entity);

				if (camera.Main)
				{
					mainCamera = &camera.Camera;
					mainCameraTransform = &transform.Transform;
					break;
				}
			}
		}

		if (mainCamera)
		{
			Renderer2D::BeginScene(*mainCamera, *mainCameraTransform);

			// Render sprites
			{
				auto view = m_Registry.view<TransformComponent, SpriteRendererComponent>();
				for (auto entity : view)
				{
					auto& transform = view.get<TransformComponent>(entity);
					auto& sprite = view.get<SpriteRendererComponent>(entity);

					Renderer2D::DrawQuad(transform.Transform, sprite.Color);
				}
			}

			Renderer2D::EndScene();
		}
	}
}