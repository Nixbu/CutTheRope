#include "GameObjects/AirPillow.h"

AirPillow::AirPillow(const Data& ObjectData, 
	World& world, const sf::Texture& texture) : ClickableObject(ObjectData, texture)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position
    bodyDef.angle = 0.0f; // Set the initial angle
    bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.0f; // Set the linear damping
    bodyDef.angularDamping = 0.0f; // Set the angular damping

    b2PolygonShape shape;
    shape.SetAsBox(texture.getSize().x / SCALE, texture.getSize().y / SCALE);


    // Define the fixture

    fixtureDef.shape = &shape;
    fixtureDef.density = 1.5f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

}

bool AirPillow::m_registerit = FactoryManager::registerit("AirPillow",
	&AirPillowFactory::createObject);