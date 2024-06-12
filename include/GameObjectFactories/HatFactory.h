#pragma once
#include "GameObjectFactory.h"

class NonPhysicalObject;
class Hat;

class HatFactory : public  GameObjectFactory {
public:

	virtual std::shared_ptr<GameObject> createObject(const Data& ObjectData,
		b2World& world,
		const sf::Texture& texture) const override;

private:

};