//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
//-------------------------------------------------------
#include "gravity.h";

using namespace System;

void Gravity::Update(Math::Vector3& velocity)
{
	velocity.y -= kG / 10;
}