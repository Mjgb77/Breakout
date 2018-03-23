#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace Engine {
	namespace core {
		class UniqueID {
		public:
			int id;


			UniqueID();
			UniqueID(const UniqueID& orig);
			UniqueID& operator=(const UniqueID& orig);
		protected:
			static int nextID;

		};
	}
}

#endif // !_UNIQUEID_HPP_

