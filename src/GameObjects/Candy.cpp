#include "GameObjects/Candy.h"

Candy::Candy(const Data& ObjectData, World& world, const sf::Texture& texture) : 
    NonClickableObject(ObjectData,texture){

    //TODO CHANGE SETTINGS IF NEEDED
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_dynamicBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) /SCALE); // Set the initial position
    bodyDef.angle = 0.0f; // Set the initial angle
    bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.1f; // Set the linear damping
    bodyDef.angularDamping = 0.1f; // Set the angular damping

    b2CircleShape circleShape;
    circleShape.m_radius = texture.getSize().x / 2.0f / SCALE; // Set the radius (assuming square texture)


    // Define the fixture
   
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed


    this->initBody( world , bodyDef, fixtureDef);


}

bool Candy::m_registerit = FactoryManager::registerit("Candy",
    &CandyFactory::createObject);


void Candy::update()
{

    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);
}
