#include "GameObjects/GravityButton.h"


GravityButton::GravityButton(const Data& ObjectData, World& world, const sf::Texture& texture)
    : ClickableObject(ObjectData, texture), m_world(world.getWorld()), m_currentGravity(GRAVITY_WORLD),
        m_degree(ObjectData.m_angle)
{

    //TODO CHANGE SETTINGS IF NEEDED
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position
    bodyDef.angle = 0.0f; // Set the initial angle
    bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.0f; // Set the linear damping
    bodyDef.angularDamping = 0.0f; // Set the angular damping

    b2CircleShape circleShape;
    circleShape.m_radius = texture.getSize().x / 2.0f / SCALE; // Set the radius (assuming square texture)

    // Define the fixture

    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

}
void GravityButton::update(sf::Time& deltaTime)
{
   
}

void GravityButton::handleClicked()
{
    m_currentGravity = -m_currentGravity;
    m_world.SetGravity(b2Vec2(m_currentGravity.x, m_currentGravity.y));
    m_degree += 180;  //TODO FIX ROTATION
    if (m_degree >= 360.0f)
    {
        m_degree -= 360.0f;
    }
    this->setRotation(m_degree);
}


bool GravityButton::m_registerit = FactoryManager::registerit("GravityButton",
    &GravityButtonFactory::createObject);
