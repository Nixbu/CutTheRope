#include "GameObjects/Air.h"

Air::Air(const Data& ObjectData, World& world, const sf::Texture& texture) 
    : NonClickableObject(ObjectData, texture),
       m_direction(angleToDirection(ObjectData.m_angle))
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape shape;


    bodyDef.type = b2_dynamicBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position
    bodyDef.angle = angleToRadians(ObjectData.m_angle); // Set the initial angle
    bodyDef.linearVelocity.Set(m_direction.x * AIR_VELOCITY, m_direction.y * AIR_VELOCITY); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.0f; // Set the linear damping
    bodyDef.angularDamping = 0.0f; // Set the angular damping

    shape.SetAsBox(texture.getSize().x, texture.getSize().y);

    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true; // Set as sensor

    this->initBody(world, bodyDef, fixtureDef);
}

void Air::update()
{
    //TODO maybe add opeator*(b2Vec2, float) for nicer multiplication
    this->SetLinearVelocity(b2Vec2(m_direction.x * AIR_VELOCITY, m_direction.y * AIR_VELOCITY)); 

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

}

bool Air::m_registerit = FactoryManager::registerit("Air",
    &AirFactory::createObject);