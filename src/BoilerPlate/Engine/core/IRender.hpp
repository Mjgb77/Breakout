#pragma once
#ifndef _IRENDER_HPP_
#define _IRENDER_HPP_

namespace Engine
{
	namespace core
	{
		class IRender {
		public:
			virtual ~IRender() = default;
			
			void virtual render() = 0;


		};
	}
}


#endif // !_IRENDER_HPP_

