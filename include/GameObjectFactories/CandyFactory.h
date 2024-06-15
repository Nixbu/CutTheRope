#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Candy.h"


class CandyFactory{
public:

	static std::shared_ptr<GameObject> createObject(const Data& ObjectData, b2World& world, const sf::Texture& texture);

private:

};