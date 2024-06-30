#include "GameObjects/Star.h"


//===================================================================
// Constructs a Star object based on provided data and initializes
// its Box2D body and fixture definitions.
//===================================================================
Star::Star(const Data& ObjectData, World& world, const sf::Texture& texture) : NonClickableObject(ObjectData, texture)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE, (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE);
    bodyDef.angle = 0.0f;

    b2PolygonShape polygonShape;
    float width = texture.getSize().x / SCALE;
    float height = texture.getSize().y / SCALE;
    polygonShape.SetAsBox(width / 5.0f, height / 5.0f);

    fixtureDef.shape = &polygonShape;

    this->initBody(world, bodyDef, fixtureDef);
}


//===================================================================
// register to the factory
bool Star::m_registerit = FactoryManager::registerit("Star",
    &StarFactory::createObject);
//===================================================================
// Updates the position and rotation of the star based on its Box2D
// body's current state.
//===================================================================
void Star::update(sf::Time& deltaTime)
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}




