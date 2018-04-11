#pragma once
#ifndef _IUPDATE_HPP_
#define _IUPDATE_HPP_



namespace Engine
{
	namespace core
	{
		class IUpdate
		{
		public:
			int m_nUpdates;

			IUpdate() : m_nUpdates(0) {};
			virtual ~IUpdate() = default;

			void virtual update(double deltaTime) { m_nUpdates++; }; 

		};
	}
}

#endif // !_IUPDATE_HPP_