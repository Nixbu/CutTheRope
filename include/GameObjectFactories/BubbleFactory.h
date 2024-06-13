#pragma once
#include "GameObjectFactory.h"


class Bubble;

class BubbleFactory :public  GameObjectFactory {
public:

	virtual std::shared_ptr<GameObject> createObject(const Data& ObjectData, b2World& world, const sf::Texture& texture) const;

private:

};