#include "game_object.hpp"

// STL
#include <algorithm>

// 
#include "Component.hpp"

namespace Engine
{
	namespace core
	{
		game_object::game_object()
			: m_parent(nullptr)
		{}

		game_object::~game_object()
		{
			// Delete all attached components
			//
			while (!m_components.empty()) delete m_components.back(), m_components.pop_back();

			// Delete all attached children
			//
			while (!m_children.empty()) delete m_children.back(), m_children.pop_back();
		}

		void game_object::attach_component(component* component)
		{
			component->set_owner(this);
			m_components.push_back(component);
		}

		void game_object::remove_component(component* component)
		{
			m_components.erase(
				remove(m_components.begin(), m_components.end(), component), m_components.end()
			);

			delete component;
		}

		void game_object::add_child(game_object* child)
		{
			// Set the child parent
			child->m_parent = this;

			// 
			m_children.push_back(child);
		}

		void game_object::remove_child(game_object* child)
		{
			m_children.erase(
				remove(m_children.begin(), m_children.end(), child), m_children.end()
			);

			delete child;
		}

		void game_object::update(double deltaTime)
		{
			// Update components
			//
			std::vector< component* >::iterator comp = m_components.begin();
			for (; comp != m_components.end(); ++comp)
			{
				(*comp)->update(deltaTime);
			}

			// Update children
			//
			std::vector< game_object* >::iterator child = m_children.begin();
			for (; child != m_children.end(); ++child)
			{
				(*child)->update(deltaTime);
			}

			// Base class function call
			//
			IUpdate::update(deltaTime);
		}

		void game_object::render()
		{
			//if ((m_nUpdates % 60) == 0)
			{
				// Render children
				//
				std::vector< game_object* >::iterator child = m_children.begin();
				for (; child != m_children.end(); ++child)
				{
					(*child)->render();
				}
			}
		}

		void game_object::init_quad_vertices(float * pVerticesArray, Color pColor)
		{
			std::vector <VertexObject> vertices;

			vertices.push_back(
				VertexObject(Engine::Math::Vector2(1.0f,1.0f), pColor, Engine::Math::Vector2(1.0f, 1.0f))
			);
			vertices.push_back(
				VertexObject(Engine::Math::Vector2(1.0f, -1.0f), pColor, Engine::Math::Vector2(1.0f, 0.0f))
			);
			vertices.push_back(
				VertexObject(Engine::Math::Vector2(-1.0f, -1.0f), pColor, Engine::Math::Vector2(0.0f, 0.0f))
			);
			vertices.push_back(
				VertexObject(Engine::Math::Vector2(-1.0f, 1.0f), pColor, Engine::Math::Vector2(0.0f, 1.0f))
			);

			int id = 0;
			for (VertexObject &V : vertices) {
				V.copy_info(pVerticesArray + id);
				id += 9;
			}

		}
	}

}