#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "IUpdate.hpp"
#include "IRender.hpp"
#include "unique_id.hpp"
#include "Renderer.hpp"

namespace Engine
{
	namespace core
	{
		class component;
		class game_object : public IUpdate, public IRender, public unique_id
		{
		public:
			//constructor
			game_object();
			~game_object();

			// PUBLIC FUNCTIONS
			
			void attach_component(component*);
			void remove_component(component*);
			void add_child(game_object*);
			void remove_child(game_object*);
			void update(double deltaTime) override;
			void render() override;
			
			// GETTER FUNCTIONS
		
			std::vector<component*>get_components() const { return m_components; }
			std::vector<game_object*> get_children() const { return m_children; }
			game_object* GetParent() const { return m_parent; }

			template<typename T>
			T* get_component()
			{
				// If no components have been attached then return nothing
				//
				if (m_components.size() == 0) return nullptr;

				std::vector< component* >::iterator comp = m_components.begin();
				for (; comp != m_components.end(); ++comp)
				{
					T* theComponent = dynamic_cast<T*>(*comp);
					if (theComponent)
					{
						return theComponent;
					}
				}

				return nullptr;
			}
		protected:
			
			// MEMBERS
			
			std::vector<component*>	m_components;
			std::vector<game_object*> m_children;
			
			game_object* m_parent;
			renderer * m_renderer;

			// FUNCTIONS
			void init_quad_vertices(float *, Color);
		};

	}
}

#endif // !_GAMEOBJECT_HPP_