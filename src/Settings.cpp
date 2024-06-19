#include "Settings.h"

b2Vec2 angleToDirection(float angle)
{
	float radians = angle * DEG2RAD;
	return b2Vec2(cos(radians), sin(radians));
}

float angleToRadians(float angle) {
	return angle * DEG2RAD;
}