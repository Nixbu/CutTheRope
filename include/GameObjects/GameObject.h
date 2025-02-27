#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <box2d/box2d.h>
#include "Settings.h"

class World;

/*
   The GameObject class represents a base class for all game objects.
   It manages properties such as position, rotation, physics body, and provides methods for drawing and updating.
*/
class GameObject
{
public:
    GameObject(const Data& objectData, const sf::Texture& texture);
    virtual ~GameObject();

    sf::Vector2f getPosition() const;
    sf::Sprite& getSprite();
    float getRotationAngle() const;
    sf::Vector2f getSize() const;
    void setPosition(float posX, float posY);
    void setRotation(float angle);
    virtual void draw(sf::RenderWindow& window) const;
    virtual void update(sf::Time& deltaTime);
    void initBody(World& world,
        const b2BodyDef& bodyDef,
        const b2FixtureDef& fixtureDef);
    virtual b2Body* getBody();
    void SetLinearVelocity(const b2Vec2 linearVelocity);
    void setToDynamic();
    void setDelete();
    bool needToDelete() const;

private:
    sf::Sprite m_sprite;
    bool m_toDelete;
    std::unique_ptr<b2Body, void(*)(b2Body*)> m_body;
};

//===================================================================
// Custom deleter for b2Body
//===================================================================
void b2BodyDeleter(b2Body* body);