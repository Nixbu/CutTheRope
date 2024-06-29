#include "GameObjects/Omnom.h"

Omnom::Omnom(const Data& ObjectData, World& world, const sf::Texture& texture) : 
    NonClickableObject(ObjectData, texture) ,
    m_animation(ResourceManager::getInstance().getAnimation(ObjectData.m_type), 
        this->getSprite(),
        false)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE);
    bodyDef.angle = 0.0f;

    b2PolygonShape polygonShape;
    float width = texture.getSize().x / SCALE;
    float height = texture.getSize().y / SCALE;
    polygonShape.SetAsBox(0.5, 0.5);

    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.3f;

    this->initBody(world, bodyDef, fixtureDef);

    sf::Vector2f origin(OMNOM_SIZE.x / 2.0f,
        OMNOM_SIZE.y / 2.0f);
    this->getSprite().setOrigin(origin);
}

bool Omnom::m_registerit = FactoryManager::registerit("Omnom",
    &OmnomFactory::createObject);

void Omnom::update(sf::Time& deltaTime)
{
    this->m_animation.update(deltaTime);
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}

void Omnom::setAnimationFlag(const bool& flag)
{
    this->m_animation.setAnimationFlag(flag);
}
