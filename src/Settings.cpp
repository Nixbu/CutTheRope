#include "Settings.h"

b2Vec2 angleToDirection(float angle)
{
	float angleRadians = angle * DEG2RAD;
	return b2Vec2(std::sin(angleRadians), std::cos(angleRadians));
}

float angleToRadians(float angle) {
	return angle * DEG2RAD;
}