#include "GameObjects/GameObject.h"

GameObject::GameObject(sf::Vector2f position, const sf::Texture& texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(texture);
}

sf::Vector2f GameObject::getPosition() const
{
	return this->m_sprite.getPosition();
}

void GameObject::setPosition(sf::Vector2f& position)
{
	this->m_sprite.setPosition(position.x, position.y);
}

GameObject::~GameObject()
{
}
