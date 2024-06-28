#pragma once

#include "GameObjects/GameObject.h"
#include "box2d/box2d.h"
#include "Settings.h"

class ClickableObject : public GameObject
{
public:
	ClickableObject(const Data& data, const sf::Texture& texture);
	virtual bool isClicked(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos);
	virtual void handleClicked() = 0;

	virtual ~ClickableObject();
private:
};