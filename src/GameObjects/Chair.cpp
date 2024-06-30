#include "GameObjects/Chair.h"

//===================================================================
// Constructs a Chair object using the provided data and texture.
//===================================================================
Chair::Chair(const Data& ObjectData, World& world, const sf::Texture& texture)
    : NonClickableObject(ObjectData, texture)
{
    b2BodyDef bodyDef;

    bodyDef.type = b2_staticBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); 

    b2PolygonShape shape;
    shape.SetAsBox(texture.getSize().x / SCALE, texture.getSize().y / SCALE);

    // Define the fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;


    this->initBody(world, bodyDef, fixtureDef);
}


//===================================================================
// for the factory
//===================================================================
bool Chair::m_registerit = FactoryManager::registerit("Chair",
    &ChairFactory::createObject);