#pragma once

#include "GameObjects/GameObject.h"
#include "Settings.h"


class NonPhysicalObject : public GameObject
{
public:
	NonPhysicalObject(const Data& data, const sf::Texture& texture);
	virtual ~NonPhysicalObject() = 0;
private:

};