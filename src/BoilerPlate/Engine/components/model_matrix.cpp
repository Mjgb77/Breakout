#include "model_matrix.hpp"

model_matrix::model_matrix():Component("Model_Matrix")
{

}

float * model_matrix::get_pointer_table()
{
	return mMatrix.get_pointer();
}

void model_matrix::scale(Engine::Math::Vector3 pScaleVector)
{
	mMatrix.scale(pScaleVector);
}

void model_matrix::translate(Engine::Math::Vector3 pTranslationVector)
{
	mMatrix.translate(pTranslationVector);
}


model_matrix::~model_matrix()
{
}
