#include "GameObjects/Spikes.h"


Spikes::Spikes(const Data& ObjectData, b2World& world, const sf::Texture& texture) :
    NonClickableObject(ObjectData, texture) {

    //TODO CHANGE SETTINGS IF NEEDED
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x, ObjectData.m_pos.y); // Set the initial position
    bodyDef.angle = 0.0f; // Set the initial angle
    bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.1f; // Set the linear damping
    bodyDef.angularDamping = 0.1f; // Set the angular damping

    b2PolygonShape polygonShape;
    float width = texture.getSize().x / SCALE;
    float height = texture.getSize().y / SCALE;

    // Set as a box shape for now, can be modified for other shapes
    polygonShape.SetAsBox(width / 2.0f, height / 2.0f);

    // Define the fixture

    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed


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

