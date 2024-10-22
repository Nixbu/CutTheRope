#include "GameObjects/GameObject.h"
#include "GameObjects/NonClickableObject.h"
#include "GameObjects/ClickableObject.h"
#include "World.h"
#include <memory>

//===================================================================
// Custom deleter for b2Body
//===================================================================
void b2BodyDeleter(b2Body* body) {
    if (body) {
        body->GetWorld()->DestroyBody(body);
    }
}

//===================================================================
// Constructs a GameObject using the provided data and texture, setting
// its initial position, rotation, and origin based on the texture size.
//===================================================================
GameObject::GameObject(const Data& objectData, const sf::Texture& texture)
    : m_toDelete(false), m_body(nullptr, b2BodyDeleter)
{
    m_sprite.setTexture(texture);
    m_sprite.setPosition(objectData.m_pos);
    m_sprite.setRotation(objectData.m_angle);
    // Calculate the origin based on the texture size
    sf::Vector2f origin(m_sprite.getLocalBounds().width / 2.0f,
        m_sprite.getLocalBounds().height / 2.0f);

    m_sprite.setOrigin(origin);
}

//===================================================================
sf::Vector2f GameObject::getPosition() const
{
    return this->m_sprite.getPosition();
}

//===================================================================
sf::Sprite& GameObject::getSprite()
{
    return m_sprite;
}

//===================================================================
float GameObject::getRotationAngle() const
{
    return m_sprite.getRotation();
}

//===================================================================
sf::Vector2f GameObject::getSize() const
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    return sf::Vector2f(bounds.width, bounds.height);
}

//===================================================================
void GameObject::setPosition(float posX, float posY)
{
    this->m_sprite.setPosition(sf::Vector2f(posX, posY));
}

//===================================================================
void GameObject::setRotation(float angle)
{
    this->m_sprite.setRotation(angle);
}

//===================================================================
// Destructor is now empty as unique_ptr handles body deletion
//===================================================================
GameObject::~GameObject() = default;

//===================================================================
void GameObject::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}

//===================================================================
// Updates the game object's position and rotation based on its Box2D
// body state.
//===================================================================
void GameObject::update(sf::Time& deltaTime)
{
    if (m_body) {
        b2Vec2 position = m_body->GetPosition();
        float angle = m_body->GetAngle();

        // Convert Box2D position (meters) to SFML position (pixels)
        this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
        this->setRotation(angle * 180.0f / b2_pi);
    }
}

//===================================================================
// Initializes the Box2D body of the game object using the provided world,
// body definition, and fixture definition
//===================================================================
void GameObject::initBody(World& world, const b2BodyDef& bodyDef, const b2FixtureDef& fixtureDef)
{
    m_body.reset(world.getWorld().CreateBody(&bodyDef));
    m_body->CreateFixture(&fixtureDef);
    auto& pos = m_body->GetPosition();
    this->setPosition(pos.x * SCALE, pos.y * SCALE);
}

//===================================================================
b2Body* GameObject::getBody()
{
    return m_body.get();
}

//===================================================================
void GameObject::SetLinearVelocity(const b2Vec2 linearVelocity)
{
    if (m_body) {
        m_body->SetLinearVelocity(linearVelocity);
    }
}

//===================================================================
void GameObject::setToDynamic()
{
    if (m_body) {
        m_body->SetType(b2_dynamicBody);
    }
}

//===================================================================
void GameObject::setDelete()
{
    this->m_toDelete = true;
}

//===================================================================
bool GameObject::needToDelete() const
{
    return this->m_toDelete;
}