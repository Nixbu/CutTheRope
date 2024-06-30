#include "GameObjects/Hat.h"

//===================================================================
// Constructs a Hat object using provided data, initializing it as
// a NonClickableObject with a static body definition and sensor fixture.
//===================================================================
Hat::Hat(const Data& ObjectData, World& world, const sf::Texture& texture)
	: NonClickableObject(ObjectData, texture)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); 
    bodyDef.angle = angleToRadians(ObjectData.m_angle); 


    b2PolygonShape shape;
    shape.SetAsBox(texture.getSize().x / 5.0f / SCALE, texture.getSize().y / 5.0f / SCALE);


    // Define the fixture
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);
}

