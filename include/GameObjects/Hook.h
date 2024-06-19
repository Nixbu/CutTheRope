#pragma once
#include "Settings.h"
#include "Gameobjects/NonClickableObject.h"

class World;

class Hook : public NonClickableObject  {
public:
	Hook(const Data& data, World& world, const sf::Texture& texture);
	virtual void update() override;
private:
	static bool m_registerIt;
};