#include "GameObjects/AirPillow.h"

AirPillow::AirPillow(const Data& ObjectData, 
	World& world, const sf::Texture& texture) : 
    ClickableObject(ObjectData, texture),
    m_data(ObjectData), m_world(world), 
    m_animation(ResourceManager::getInstance().getAnimation(ObjectData.m_type), \
                this->getSprite(),
                   false)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    bodyDef.type = b2_staticBody; // Set the body type to dynamic
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); // Set the initial position
    bodyDef.angle = angleToRadians(ObjectData.m_angle); // Set the initial angle
    bodyDef.linearVelocity.Set(0.0f, 0.0f); // Set the initial linear velocity
    bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    bodyDef.linearDamping = 0.0f; // Set the linear damping
    bodyDef.angularDamping = 0.0f; // Set the angular damping

    b2PolygonShape shape;
    shape.SetAsBox(AIR_PILLOW_SIZE.x / SCALE, AIR_PILLOW_SIZE.y / SCALE);


    // Define the fixture

    fixtureDef.shape = &shape;
    fixtureDef.density = 1.5f; // Adjust density as needed
    fixtureDef.friction = 0.3f; // Adjust friction as needed
    fixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    // Set Origin
    sf::Vector2f origin(AIR_PILLOW_SIZE.x / 2.0f,
        AIR_PILLOW_SIZE.y / 2.0f);
    this->getSprite().setOrigin(origin);

}

void AirPillow::handleClicked()
{
    this->m_animation.setAnimationFlag(true);
    auto& resourceManager = ResourceManager::getInstance();
    const sf::Texture& texture = resourceManager.getImage("Air");
    auto airBullet = std::make_shared<Air>(m_data, m_world, texture);
    
    ResourceManager::getInstance().playSound("GhostPuff");

    this->m_world.addToGameObjects(airBullet);
}

void AirPillow::update(sf::Time& deltaTime)
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);


    this->m_animation.update(deltaTime);
}



bool AirPillow::m_registerit = FactoryManager::registerit("AirPillow",
	&AirPillowFactory::createObject);