#pragma once
#include "GameObjectFactory.h"


class Candy;

class CandyFactory :public  GameObjectFactory {
public:

	virtual std::unique_ptr<GameObject> createGameObject(const Data& objectData , b2World& world) const;
private:

};