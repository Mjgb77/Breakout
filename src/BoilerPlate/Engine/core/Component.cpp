#include "Component.hpp"

namespace Engine
{
	namespace core
	{
		component::component(const std::string& name)
			: m_name(name)
		{}

		component::~component()
		{
			m_owner = nullptr;
		}

		void component::update(double deltaTime)
		{
			IUpdate::update(deltaTime);
		}
	}
}