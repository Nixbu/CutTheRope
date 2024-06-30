#include "GameObjects/Bubble.h"

//===================================================================
//===================================================================
Bubble::Bubble(const Data& ObjectData, World& world, const sf::Texture& texture) 
    : ClickableObject(ObjectData, texture),
    m_animation(ResourceManager::getInstance().getAnimation(ObjectData.m_type), 
        this->getSprite(),
        true)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE , (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); 

    b2CircleShape circleShape;
    circleShape.m_radius = BUBBLE_SIZE.x / 2.0f / SCALE; 

    
    // Define the fixture
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; 
    fixtureDef.friction = 0.3f; 
    fixtureDef.restitution = 0.5f; 
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    // Set Origin
    sf::Vector2f origin(AIR_PILLOW_SIZE.x / 2.0f,
        AIR_PILLOW_SIZE.y / 2.0f);
    this->getSprite().setOrigin(origin);

}
//===================================================================
//Changes the Bubble from a static body to a dynamic body, sets the
// animation flag to true, and applies an initial velocity.
//===================================================================
void Bubble::changeToDynamic()
{
    this->m_animation.setAnimationFlag(true);
    this->setToDynamic();
    this->SetLinearVelocity(BUBBLE_VELOCITY);
}
//===================================================================
// Updates the Bubble's position, rotation, and animation based on the 
// current Box2D state. Applies a force to the center if the Bubble 
// is dynamic.
//===================================================================
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
//===================================================================
// Handles the click event for the Bubble. If the Bubble is dynamic,
// plays the "BubbleBreak" sound and marks the Bubble for deletion.
//===================================================================
void Bubble::handleClicked()
{
    if (this->getBody()->GetType() == b2_dynamicBody) 
    {
        ResourceManager::getInstance().playSound("BubbleBreak");
        this->setDelete();   
    }
}
//===================================================================
// for the factory
//===================================================================
bool Bubble::m_registerit = FactoryManager::registerit("Bubble",
    &BubbleFactory::createObject);
