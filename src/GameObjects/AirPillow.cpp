#include "GameObjects/AirPillow.h"

//===================================================================
//Constructs an AirPillow object using the provided data and texture
//===================================================================
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

    bodyDef.type = b2_staticBody; 
    bodyDef.position.Set(ObjectData.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - ObjectData.m_pos.y) / SCALE); 
    bodyDef.angle = angleToRadians(ObjectData.m_angle); 

    b2PolygonShape shape;
    shape.SetAsBox(AIR_PILLOW_SIZE.x / SCALE, AIR_PILLOW_SIZE.y / SCALE);


    
    // Define the fixture
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;

    this->initBody(world, bodyDef, fixtureDef);

    // Set Origin
    sf::Vector2f origin(AIR_PILLOW_SIZE.x / 2.0f,
        AIR_PILLOW_SIZE.y / 2.0f);
    this->getSprite().setOrigin(origin);

}
//===================================================================
// Handles the click event for the AirPillow. Starts the animation,
// creates an Air object, plays the "GhostPuff" sound, and adds the
// Air object to the game world.
//===================================================================
void AirPillow::handleClicked()
{
    this->m_animation.setAnimationFlag(true);
    auto& resourceManager = ResourceManager::getInstance();
    const sf::Texture& texture = resourceManager.getImage("Air");

    //Add AirBullet
    this->m_world.addToGameObjects(std::make_unique<Air>(m_data, m_world, texture));

    ResourceManager::getInstance().playSound("GhostPuff");

}
//===================================================================
// Updates the AirPillow's position, rotation, and animation based on the 
// current Box2D state.
//===================================================================
void AirPillow::update(sf::Time& deltaTime)
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);


    this->m_animation.update(deltaTime);
}


//===================================================================
// for the factory
//===================================================================
bool AirPillow::m_registerit = FactoryManager::registerit("AirPillow",
	&AirPillowFactory::createObject);