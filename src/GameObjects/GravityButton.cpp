#include "GameObjects/GravityButton.h"

//===================================================================
// Constructs a GravityButton object using provided data, initializing it as
// a ClickableObject with a static body definition and sensor fixture.
//===================================================================
GravityButton::GravityButton(const Data& ObjectData, World& world, const sf::Texture& texture)
    : ClickableObject(ObjectData, texture), m_world(world.getWorld()), m_currentGravity(GRAVITY_WORLD)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE);
    bodyDef.angle = 0.0f; // Set the initial angle


    b2CircleShape circleShape;
    circleShape.m_radius = texture.getSize().x / 2.0f / SCALE; 

    // Define the fixture

    fixtureDef.shape = &circleShape;
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

} 

//===================================================================
// Handles the click event for the gravity button.
//===================================================================
void GravityButton::handleClicked()
{
    m_currentGravity = -m_currentGravity;
    m_world.SetGravity(b2Vec2(m_currentGravity.x, m_currentGravity.y));
    if (m_currentGravity.y > 0.f )
    {
        this->getSprite().setTexture(ResourceManager::getInstance().getImage("GravityButtonDown"));
        ResourceManager::getInstance().playSound("GravityOn");
    }
    else
    {
        this->getSprite().setTexture(ResourceManager::getInstance().getImage("GravityButtonUp"));
        ResourceManager::getInstance().playSound("GravityOff");

    }
}

//===================================================================
// for factory
//===================================================================
bool GravityButton::m_registerit = FactoryManager::registerit("GravityButton",
    &GravityButtonFactory::createObject);
