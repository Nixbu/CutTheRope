#include "GameObjects/Spikes.h"


Spikes::Spikes(const Data& ObjectData, World& world, const sf::Texture& texture) :
    NonClickableObject(ObjectData, texture)
{

    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE);
    bodyDef.angle = angleToRadians(ObjectData.m_angle);

    b2PolygonShape polygonShape;
    float width = texture.getSize().x / SCALE;
    float height = texture.getSize().y / SCALE;
    polygonShape.SetAsBox(width / 2.0f, height / 2.0f);

    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.3f;

    this->initBody(world, bodyDef, fixtureDef);
}

void Spikes::update()
{
    
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}

bool Spikes::m_registerit = FactoryManager::registerit("Spikes",
    &SpikesFactory::createObject);

