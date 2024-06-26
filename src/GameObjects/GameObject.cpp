#include "GameObjects/GameObject.h"
#include "GameObjects/NonClickableObject.h"
#include "GameObjects/ClickableObject.h"
#include "World.h"


GameObject::GameObject(const Data& objectData, const sf::Texture& texture)
	: m_toDelete(false), m_body(nullptr)
{
	m_sprite.setPosition(objectData.m_pos);
	m_sprite.setRotation(objectData.m_angle);
	m_sprite.setTexture(texture);
	// Calculate the origin based on the texture size
	sf::Vector2f origin(m_sprite.getLocalBounds().width / 2.0f,
		m_sprite.getLocalBounds().height / 2.0f);

	m_sprite.setOrigin(origin);
}

sf::Vector2f GameObject::getPosition() const
{
	return this->m_sprite.getPosition();
}

const sf::Sprite& GameObject::getSprite() const
{
	return m_sprite;
}

float GameObject::getRotationAngle() const
{
	return m_sprite.getRotation();
}

sf::Vector2f GameObject::getSize() const
{
	sf::FloatRect bounds = m_sprite.getGlobalBounds();
	return sf::Vector2f(bounds.width, bounds.height);
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
	if (m_body) {
		m_body->GetWorld()->DestroyBody(m_body);
	}
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::initBody(World& world, const b2BodyDef& bodyDef, const b2FixtureDef& fixtureDef)
{
	m_body = world.getWorld().CreateBody(&bodyDef);
	this->m_body->CreateFixture(&fixtureDef);
	auto& pos = this->m_body->GetPosition();
	this->setPosition(pos.x *SCALE, pos.y*SCALE);
}

b2Body* GameObject::getBody()
{
	
	return m_body;
}

void GameObject::SetLinearVelocity(const b2Vec2 linearVelocity)
{
	this->m_body->SetLinearVelocity(linearVelocity);
}

void GameObject::setToDynamic()
{
	this->m_body->SetType(b2_dynamicBody);
}

void GameObject::setDelete()
{
	this->m_toDelete = true;
}

bool GameObject::needToDelete() const
{
	return this->m_toDelete;
}
