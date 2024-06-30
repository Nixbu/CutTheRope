#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/BubbleFactory.h"
#include "GameObjects/ClickableObject.h"
#include "Animations/Animation.h"

/*
   class Bubble
   The Bubble class represents a clickable bubble object in the game.
   It extends ClickableObject and manages its own animation and state changes.
*/

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