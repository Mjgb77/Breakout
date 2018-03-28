#pragma once
#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "game_object.hpp"
#include "vertex.hpp"
namespace Engine {
	namespace core {
		class Ball : GameObject {
		public:
			//Ball();
			Vertex mVertexes[12] ;
			int indexes;
		};
	}
}


#endif // ! BALL_H_INCLUDED

