#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <box2d/box2d.h>



class GameObject
{
public:
	GameObject(sf::Vector2f position, const sf::Texture& texture);
	sf::Vector2f getPosition() const;
	void setPosition(float posX, float posY);
	void setRotation(float angle);
	virtual ~GameObject() = 0;
	void draw(sf::RenderWindow& window) const;
	virtual void update() = 0;
	virtual b2Body* getBody() = 0;
	virtual bool isClicked(const sf::Vector2f& mousePos) const;
	virtual void handleClicked() = 0;
	void setDelete();
	bool needToDelete()const;

private:
	sf::Sprite m_sprite;
	bool m_toDelete;
};