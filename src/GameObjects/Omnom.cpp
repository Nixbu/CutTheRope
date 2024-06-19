#include "GameObjects/Omnom.h"

Omnom::Omnom(const Data& ObjectData, World& world, const sf::Texture& texture) : 
    NonClickableObject(ObjectData, texture) 
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE);
    bodyDef.angle = 0.0f;

    b2PolygonShape polygonShape;
    float width = texture.getSize().x / SCALE;
    float height = texture.getSize().y / SCALE;
    polygonShape.SetAsBox(width / SCALE, height / SCALE);

    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.3f;

    this->initBody(world, bodyDef, fixtureDef);
}

bool Omnom::m_registerit = FactoryManager::registerit("Omnom",
    &OmnomFactory::createObject);
