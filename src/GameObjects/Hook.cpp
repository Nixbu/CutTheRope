#include "Gameobjects/Hook.h"
#include "World.h"
//===================================================================
// Constructs a Hook object using provided data, initializing it as
// a NonClickableObject with a static body definition and sensor fixture.
//===================================================================
Hook::Hook(const Data& data, World& world, const sf::Texture& texture) : NonClickableObject(data, texture)
{
    b2Vec2 currentPosition = b2Vec2(data.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - data.m_pos.y) / SCALE);

    // Define the hook static body
    b2BodyDef hookBodyDef;
    hookBodyDef.position = currentPosition; // Hook position is the same as the start of the rope
    hookBodyDef.type = b2_staticBody;


    b2PolygonShape hookShape;
    hookShape.SetAsBox(0.1f, 0.1f); // Define hook size

    b2FixtureDef hookFixtureDef;
    hookFixtureDef.isSensor = true;
    hookFixtureDef.shape = &hookShape;

    this->initBody(world, hookBodyDef, hookFixtureDef);

}
//===================================================================
// Updates the position and rotation of the Hook object based on its
// Box2D physics body.
//===================================================================
void Hook::update(sf::Time& deltaTime)
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}
