#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(sf::Vector2f position, const sf::Texture& texture);
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f& position);

private:
	sf::Sprite m_sprite;
};