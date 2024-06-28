#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/BubbleFactory.h"
#include "GameObjects/ClickableObject.h"
#include "Animations/Animation.h"

class Bubble : public ClickableObject
{
public:
	Bubble(const Data& ObjectData, World& world, const sf::Texture& texture);
	void changeToDynamic();
	virtual void update(sf::Time& deltaTime);
	virtual void handleClicked();

private:
	static bool m_registerit;
	Animation m_animation;

};