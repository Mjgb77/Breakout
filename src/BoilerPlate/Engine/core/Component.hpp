#pragma once
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED
#include <string>

#include "IUpdate.hpp"

namespace Engine
{
	namespace core {
		class game_object;
		class component :public IUpdate
		{
		public:
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			void set_owner(game_object* pOwner) { m_owner = pOwner; }
			game_object* get_Owner() const { return m_owner; }
			std::string get_Name() const { return m_name; }
		protected:
			game_object * m_owner;
			std::string m_name;
		};
	}
}



#endif // !COMPONENT_H_INCLUDED