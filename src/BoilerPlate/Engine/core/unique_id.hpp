#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace Engine {
	namespace core {
		class unique_id {
		public:
			int id;


			unique_id();
			unique_id(const unique_id& orig);
			unique_id& operator=(const unique_id& orig);
		protected:
			static int nextID;

		};
	}
}

#endif // !_UNIQUEID_HPP_

