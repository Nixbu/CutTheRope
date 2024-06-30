#include "GameObjects/Candy.h"

//===================================================================
// Constructs a Candy object using the provided data and texture.
//===================================================================
Candy::Candy(const Data& ObjectData, World& world, const sf::Texture& texture) : 
    NonClickableObject(ObjectData,texture)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_dynamicBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) /SCALE); 
    bodyDef.angle = 0.0f; 
    bodyDef.linearVelocity.Set(0.0f, 0.0f); 
    bodyDef.angularVelocity = 0.0f; 
    bodyDef.linearDamping = 0.1f; 
    bodyDef.angularDamping = 0.1f; 

    b2CircleShape circleShape;
    circleShape.m_radius = texture.getSize().x / 2.0f / SCALE; 


    
    // Define the fixture
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.5f; 
    fixtureDef.friction = 0.3f; 
    fixtureDef.restitution = 0.5f; 


    this->initBody( world , bodyDef, fixtureDef);
}
//===================================================================
// for the factory
//===================================================================
bool Candy::m_registerit = FactoryManager::registerit("Candy",
    &CandyFactory::createObject);



