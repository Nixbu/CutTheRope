#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/Candy.h"

std::unique_ptr<GameObject> CandyFactory::createGameObject(const Data& objectData , b2World& world) const {

	return std::make_unique<Candy>(objectData , world);
}