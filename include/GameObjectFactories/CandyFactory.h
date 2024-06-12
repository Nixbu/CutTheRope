#pragma once
#include "GameObjectFactory.h"


class Candy;

class CandyFactory :public  GameObjectFactory {
public:

	virtual std::unique_ptr<GameObject> && createObject(const Data& ObjectData, b2World& world) const;

private:

};