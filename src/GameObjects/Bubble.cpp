#include "GameObjects/Bubble.h"


Bubble::Bubble(const Data& ObjectData, World& world, const sf::Texture& texture) 
    : ClickableObject(ObjectData, texture),
    m_animation(ResourceManager::getInstance().getAnimation(ObjectData.m_type), 
        this->getSprite(),
        true)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE , (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position

    b2CircleShape circleShape;
    circleShape.m_radius = BUBBLE_SIZE.x / 2.0f / SCALE; // Set the radius (assuming square texture)

    // Define the fixture

    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    // Set Origin
    sf::Vector2f origin(AIR_PILLOW_SIZE.x / 2.0f,
        AIR_PILLOW_SIZE.y / 2.0f);
    this->getSprite().setOrigin(origin);

}

void Bubble::changeToDynamic()
{
    this->m_animation.setAnimationFlag(true);
    this->setToDynamic();
    this->SetLinearVelocity(BUBBLE_VELOCITY);
}

void Bubble::update(sf::Time& deltaTime)
{
    if (this->getBody()->GetType() == b2_dynamicBody)
    {
        this->getBody()->ApplyForceToCenter(BUBBLE_FORCE, true);
        this->m_animation.update(deltaTime);
    }

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

  
}

void Bubble::handleClicked()
{
    if (this->getBody()->GetType() == b2_dynamicBody) {
        this->setDelete();      
    }
}


bool Bubble::m_registerit = FactoryManager::registerit("Bubble",
    &BubbleFactory::createObject);
