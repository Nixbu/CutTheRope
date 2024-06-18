#pragma once

#include "GameObjects/GameObject.h"
#include "box2d/box2d.h"
#include "Settings.h"

class ClickableObject : public GameObject
{
public:
	ClickableObject(const Data& data, const sf::Texture& texture);
	virtual bool isClicked(const sf::Vector2f& mousePos) const;
	virtual void handleClicked() = 0;

	virtual ~ClickableObject();
private:
};