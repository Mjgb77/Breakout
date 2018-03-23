#pragma once
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED
#include <string>

#include "IUpdate.hpp"

namespace Engine
{
	namespace core {
		class GameObject;
		class Component :public IUpdate
		{
		public:
			explicit Component(const std::string& name);
			~Component();
			void Update(double deltaTime) override;

			void set_owner(GameObject* pOwner) { m_owner = pOwner; }
			GameObject* get_Owner() const { return m_owner; }
			std::string get_Name() const { return m_name; }
		protected:
			GameObject * m_owner;
			std::string m_name;
		};
	}
}



#endif // !COMPONENT_H_INCLUDED