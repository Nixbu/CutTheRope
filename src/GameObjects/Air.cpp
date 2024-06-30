#include "GameObjects/Air.h"

//===================================================================
// Constructs an Air object using the provided data and texture.
// Inherits from the NonClickableObject class.
//===================================================================
Air::Air(const Data& ObjectData, World& world, const sf::Texture& texture) 
    : NonClickableObject(ObjectData, texture),
       m_direction(angleToDirection(ObjectData.m_angle)),
        m_force(b2Vec2(m_direction.x * AIR_FORCE, m_direction.y * AIR_FORCE)),
    m_clock()
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape shape;

    // define the bodydef
    bodyDef.type = b2_dynamicBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); 
    bodyDef.angle = angleToRadians(ObjectData.m_angle); 
    bodyDef.linearVelocity.Set(m_direction.x * 30, m_direction.y * 30); 
    bodyDef.angularVelocity = 0.0f; 
    bodyDef.linearDamping = 0.2f; 
    bodyDef.angularDamping = 0.0f; 
    
    shape.SetAsBox(0.5f, 0.5f);

    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true; // Set as sensor so that physick wont affect

    this->initBody(world, bodyDef, fixtureDef);
}
//===================================================================
// Updates the Air's position, rotation, and checks its lifetime.
//===================================================================
void Air::update(sf::Time& deltaTime)
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
    
    this->checkTime();

}
//===================================================================
// Returns the force applied by the Air object.
//===================================================================
const b2Vec2 Air::getForce() const
{
    return m_force;
}
//===================================================================
// Checks if the Air object has exceeded its lifetime and sets it for
// deletion if it has.
//===================================================================
void Air::checkTime()
{
    if (this->m_clock.getElapsedTime().asSeconds() >= LIVING_AIR_TIME)
    {
        this->setDelete();
    }
}

//===================================================================
// for the factory
//===================================================================
bool Air::m_registerit = FactoryManager::registerit("Air",
    &AirFactory::createObject);