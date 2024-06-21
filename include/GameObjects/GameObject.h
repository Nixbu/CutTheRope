#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <box2d/box2d.h>
#include "Settings.h"

class World;

class GameObject
{
public:
	GameObject(const Data& objectData, const sf::Texture& texture);
	virtual ~GameObject();
	sf::Vector2f getPosition() const;
	const sf::Sprite& getSprite() const;

	void setPosition(float posX, float posY);
	void setRotation(float angle);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void update() = 0;
	void initBody(World& world,
				const b2BodyDef& bodyDef,
				const b2FixtureDef& fixtureDef);
	virtual b2Body* getBody();
	void SetLinearVelocity(const b2Vec2 linearVelocity);
	void setToDynamic();
	void setDelete();
	bool needToDelete()const;

private:
	sf::Sprite m_sprite;
	bool m_toDelete;
	b2Body* m_body;
};