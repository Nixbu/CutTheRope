#include "GameObjects/PhysicalObject.h"

PhysicalObject::PhysicalObject(const Data& data,const sf::Texture& texture) : m_body(nullptr) ,  GameObject(data.m_pos,texture)
	
{
}

void PhysicalObject::initBody(b2World& world, const b2BodyDef& bodyDef)
{
	m_body = world.CreateBody(&bodyDef);
}

PhysicalObject::~PhysicalObject()
{
	if (m_body) {
		m_body->GetWorld()->DestroyBody(m_body);
	}
}
