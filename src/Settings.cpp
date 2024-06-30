#include "Settings.h"


// Converts an angle in degrees to a direction vector.
// Returns a b2Vec2 direction vector where x is the sine and y is the cosine of the angle in radians.
b2Vec2 angleToDirection(float angle)
{
	float angleRadians = angle * DEG2RAD;
	return b2Vec2(std::sin(angleRadians), std::cos(angleRadians));
}
//=================================================================
// Converts an angle in degrees to radians.
// Returns the angle in radians.
float angleToRadians(float angle) {
	return angle * DEG2RAD;
}