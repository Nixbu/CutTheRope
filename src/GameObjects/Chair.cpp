#include "GameObjects/Chair.h"

Chair::Chair(const Data& ObjectData, World& world, const sf::Texture& texture)
    : NonClickableObject(ObjectData, texture)
{
    //TODO CHANGE SETTINGS IF NEEDED
    b2BodyDef bodyDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position

    b2PolygonShape shape;
    shape.SetAsBox(texture.getSize().x / SCALE, texture.getSize().y / SCALE);

    // Define the fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.5f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    fixtureDef.isSensor = true;


    this->initBody(world, bodyDef, fixtureDef);
}

void Chair::update()
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}

bool Chair::m_registerit = FactoryManager::registerit("Chair",
    &ChairFactory::createObject);