#include "GameObjects/Bubble.h"
#include "World.h"

Bubble::Bubble(const Data& ObjectData, b2World& world, const sf::Texture& texture) : PhysicalObject(ObjectData, texture) {

    //TODO CHANGE SETTINGS IF NEEDED

    this->m_bodyDef.type = b2_staticBody; // Set the body type to dynamic
    this->m_bodyDef.position.Set(ObjectData.m_pos.x / SCALE , (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position
    this->m_bodyDef.angle = 0.0f; // Set the initial angle
    this->m_bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    this->m_bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    this->m_bodyDef.linearDamping = 0.0f; // Set the linear damping
    this->m_bodyDef.angularDamping = 0.0f; // Set the angular damping

    b2CircleShape circleShape;
    circleShape.m_radius = texture.getSize().x / 2.0f / SCALE; // Set the radius (assuming square texture)

    // Define the fixture

    this->m_fixtureDef.shape = &circleShape;
    this->m_fixtureDef.density = 1.0f; // Adjust density as needed
    this->m_fixtureDef.friction = 0.3f; // Adjust friction as needed
    this->m_fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    this->m_fixtureDef.isSensor = true;

    this->initBody(world, m_bodyDef, m_fixtureDef);

}

void Bubble::changeToDynamic()
{
    this->getBody()->SetType(b2_dynamicBody);
    this->SetLinearVelocity(BUBBLE_VELOCITY);
}

void Bubble::update()
{

    b2Vec2 force(0.0f, 200.0f);  // Adjust the force vector as needed
    this->getBody()->ApplyForceToCenter(force, true);

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

  
}

void Bubble::handleClicked(World& world)
{
    if (this->getBody()->GetType() == b2_dynamicBody) {
        // Directly delete this object from the world
        world.removeObject(this);
    }
}


bool Bubble::m_registerit = FactoryManager::registerit("Bubble",
    &BubbleFactory::createObject);
