#include "GameObjects/GameObject.h"
#include "GameObjects/NonPhysicalObject.h"
#include "GameObjects/PhysicalObject.h"
#include "World.h"

GameObject::GameObject(sf::Vector2f position, const sf::Texture& texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(texture);
	// Calculate the origin based on the texture size
	sf::Vector2f origin(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height / 2.0f);

	m_sprite.setOrigin(origin);
}

sf::Vector2f GameObject::getPosition() const
{
	return this->m_sprite.getPosition();
}

void GameObject::setPosition(float posX, float posY)
{
	this->m_sprite.setPosition(sf::Vector2f(posX, posY));
}

void GameObject::setRotation(float angle)
{
	this->m_sprite.setRotation(angle);
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

bool GameObject::isClicked(const sf::Vector2f& mousePos) const
{
	return this->m_sprite.getGlobalBounds().contains(mousePos);
}
